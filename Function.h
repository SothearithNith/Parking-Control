#ifndef parcking_h
#define parcking_h

#include <iostream>
#include <vector>
#include <string> 
#include <conio.h>
#include "antheaderPlusPlus.h"

using namespace std;

class ParkingSlot{
	private:
	    int floor;
	    int number;
	    bool occupied;
	    string plateNumber;
	
	public:
		ParkingSlot(int floor, int number) : floor(floor), number(number), occupied(false), plateNumber("") {}
	    int getFloor() const { return floor; }
	    int getNumber() const { return number; }
	    bool isOccupied() const { return occupied; }
	    void occupy(string plate) { occupied = true; plateNumber = plate; }
	    void vacate() { occupied = false; plateNumber = ""; }
	    string getPlateNumber() const { return plateNumber; }
};

class ParkingSystem {
	public:
	    ParkingSystem() 
		{
	        for (int floor = 1; floor <= 5; ++floor) 
			{
	            for (int number = 1; number <= 10; ++number) 
				{
	                slots.push_back(ParkingSlot(floor, number));
	            }
	        }
	    }

	    void parkMotorcycle() 
		{
	        int floor;
	        do 
			{
				DrawRectangle(30, 3, 60, 1, 11);
				foreColor(7); gotoxy(52, 4);  cout << "Park Motorcycle";
				foreColor(6); gotoxy(39, 7);  cout << "Floor for motorcycle parking (1 or 2) : "; foreColor(7); cin >> floor; fflush(stdin); cin.clear();	            
	        } while (floor < 1 || floor > 2);
	
	        int slotNumber = findAvailableSlot(floor);
	
	        if (slotNumber != -1) 
			{
	            string plateNumber; 
	            foreColor(6); gotoxy(39, 9);  cout << "The plate number of the motorcycle    : "; foreColor(7); cin >> plateNumber; fflush(stdin); cin.clear();
	            foreColor(11); gotoxy(30, 11); cout << "------------------------------------------------------------";
	            
	            slots[slotNumber].occupy(plateNumber);
	            foreColor(6); gotoxy(36, 13); cout << "Motorcycle with plate number "; foreColor(7); cout << plateNumber; 
	            foreColor(6); cout << "floor "; foreColor(7); cout << floor;
				foreColor(6); cout << " parked in Slot "; foreColor(7); cout<< slotNumber + 1 << endl;
	            printTicket(floor, slotNumber);
	        } 
			else 
			{
	            cout << "No available slots for motorcycles on floor " << floor << endl;
	        }
	    }

	    void parkCar() 
		{
	        int floor;
	        do 
			{
				DrawRectangle(30, 3, 60, 1, 11);
				foreColor(7); gotoxy(58, 4);  cout << "Park Car";
				foreColor(6); gotoxy(39, 7);  cout << "Floor for car parking (3, 4, or 5): "; foreColor(7); cin >> floor; fflush(stdin); cin.clear();    
	        } while (floor < 3 || floor > 5);
	
	        int slotNumber = findAvailableSlot(floor);
	
	        if (slotNumber != -1) 
			{
	            string plateNumber;
	            foreColor(6); gotoxy(39, 9);  cout << "The plate number of the car        : "; foreColor(7); cin >> plateNumber; fflush(stdin); cin.clear(); 
	            foreColor(11); gotoxy(30, 11); cout << "------------------------------------------------------------";
	            
	            slots[slotNumber].occupy(plateNumber);
	            
	            foreColor(6); gotoxy(36, 13); cout << "Car with plate number "; foreColor(7); cout << plateNumber; 
				foreColor(6); cout << " parked in Slot "; foreColor(7); cout<< slotNumber + 1 << endl;
	            
	            printTicket(floor, slotNumber);
	        } 
			else 
			{
	            cout << "No available slots for cars on floor " << floor << endl;
	        }
	    }

	    void checkout(int floor, int slotNumber) 
		{
	        if (slotNumber >= 0 && slotNumber < slots.size()) 
			{
	            if (slots[slotNumber].getFloor() == floor && slots[slotNumber].isOccupied()) 
				{
	                string plateNumber = slots[slotNumber].getPlateNumber();
	                slots[slotNumber].vacate();
	                int hours;
	                foreColor(6); gotoxy(39, 11); cout << "Enter the number of hours parked    : "; foreColor(7); cin >> hours; cin.clear(); fflush(stdin);
	                
	                int totalCost = hours * 5;
	                foreColor(6); gotoxy(39, 13); cout << "Payment due                         : $ "; foreColor(7); cout << totalCost;
	                checkoutRecords.push_back({floor, slotNumber, plateNumber[6], hours, totalCost});
	                foreColor(11); gotoxy(30, 15); cout << "------------------------------------------------------------";
	            } 
				else 
				{
					foreColor(4);cout << "\n\t\t\t\t     Slot "; foreColor(7); cout <<  slotNumber + 1 ; 
					foreColor(4); cout << " is not occupied by a vehicle from floor "; foreColor(7); cout<< floor;
					foreColor(11); gotoxy(30, 13); cout << "------------------------------------------------------------";
					
	            }
	        } 
			else 
			{
	            cout << "Invalid slot number." << endl;
	        }
	    }

	    void printCheckoutInfo() 
		{
	        if (checkoutRecords.empty()) 
			{
	            foreColor(4); gotoxy(39, 4); cout << "No checkout records available." << endl;
	            return;
	        }
	
		    DrawRectangle(30, 3, 60, 1, 2);
			foreColor(11); gotoxy(52, 4);  cout << "Print Invoicoe";
			
			
	            foreColor(5); cout << "\n\n\t\t  " << left << setw(20) << "Plate Number" << setw(20) << "Floor" << setw(20) << "Slot Number" << setw(20) << "Hours Parked" << setw(20) << "Payment";
	        for (const auto& record : checkoutRecords) 
			{
				string vehicleType = (record.floor <= 2 ? "\n\nMotorcycle       " : "\n\nCar              "); 
	            foreColor(6); cout << vehicleType << " "; foreColor(7); cout << left << setw(20) << record.plateNumber << setw(20) << record.floor << setw(20)
	            << record.slotNumber + 1  << setw(20) << record.hours << setw(2) << "$" << setw(18) << record.totalCost << endl;
	        }
	        foreColor(2); cout << "\n\n\t\t\t     ------------------------------------------------------------";
	    }

private:
    struct CheckoutRecord {
        int floor;
        int slotNumber;
        char plateNumber[6];
        int hours;
        int totalCost;
    };

    vector<ParkingSlot> slots;
    vector<CheckoutRecord> checkoutRecords;

    int findAvailableSlot(int floor) {
        for (int i = 0; i < slots.size(); ++i) {
            if (!slots[i].isOccupied() && slots[i].getFloor() == floor) {
                return i;
            }
        }
        return -1; // No available slots
    }

    void printTicket(int floor, int slotNumber) 
	{
		DrawRectangle(30, 15, 60, 1, 2);
		foreColor(11); gotoxy(52, 16);  cout << "Motorcycle Ticket";
		foreColor(5); cout << "\n\n\t\t\t\t\t    " << left << setw(20) << "Floor" << setw(20) << "slotNumber";
		foreColor(7); cout << "\n\n\t\t\t\t\t    " << left << setw(20) << floor << setw(20) << slotNumber + 1 << endl;
		foreColor(2); gotoxy(30, 22); cout << "------------------------------------------------------------";
    }
};

#endif