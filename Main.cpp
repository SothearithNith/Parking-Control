#include <iostream>
#include <windows.h>
#include "Function.h"
#include "antheaderPlusPlus.h"

using namespace std;

//-----------------------------------
void Main();
void Menu();
//-----------------------------------

int main()
{
	SetConsoleTitle("<< (: Parking control :) >>");
	
	Main();
	
	getch();
	return 0;
}

//-------------------------------
ParkingSystem p;
//-------------------------------

void Menu()
{
	DrawRectangle(20, 5, 79, 21, 11);
	DrawRectangle(18, 4, 83, 23, 7);
	
	DrawRectangle(40, 7, 40, 1, 11);
	foreColor(7); gotoxy(46, 8);  cout << "Parcking Management System";
	
	DrawRectangle(25, 11, 21, 1, 1);
	foreColor(7); gotoxy(29, 12);  cout << "1. Motorcycle"; 
	
	DrawRectangle(73, 11, 21, 1, 1);
	foreColor(7); gotoxy(82, 12);  cout << "2. Car"; 
	
	DrawRectangle(25, 15, 21, 1, 13);
	foreColor(7); gotoxy(29, 16);  cout << "3. Check out"; 
	
	DrawRectangle(73, 15, 21, 1, 13);
	foreColor(7); gotoxy(79, 16);  cout << "4. Print"; 
	
	DrawRectangle(49, 19, 21, 1, 4);
	foreColor(7); gotoxy(55, 20);  cout << "5. Exit ";
	
	DrawRectangle(40, 23, 37, 1, 6);
	foreColor(7); gotoxy(43, 24);  cout << "Please chose options 1->4 :: ";
}

void Main()
{
	a:
	do
	{
		int n;
		system("cls");
		Menu();
		cin>>n; cin.clear(); fflush(stdin);
		
		switch(n)
		{
			case 1:
				{
					do
					{
						system("cls");
						p.parkMotorcycle();
						
						foreColor(6); cout << "\n\n\t\t       Please click any key to Motorcycle again";Sleep(200);
						cout << "and [ESC] back to Menu Parcking !!!!"; Sleep(200);
					}while(getch() != 27);
				}break;
				
			case 2:
				{
					do
					{
						system("cls");
						p.parkCar();
						
						foreColor(6); cout << "\n\n\t\t       Please click any key to Motorcycle again";Sleep(200);
						cout << "and [ESC] back to Menu Parcking !!!!"; Sleep(200);
					}while(getch() != 27);
				}break;
				
			case 3:
				{
					do
					{
						system("cls");
						int floor;
						int slotNumber;
						DrawRectangle(30, 3, 60, 1, 11);
						foreColor(7); gotoxy(56, 4); cout << "Check out";						
						foreColor(6); gotoxy(39, 7); cout << "Enter the floor number for checkout : "; foreColor(7); cin >> floor;      cin.clear(); fflush(stdin);
               			foreColor(6); gotoxy(39, 9); cout << "Enter the slot number for checkout  : "; foreColor(7); cin >> slotNumber; cin.clear(); fflush(stdin);

		                p.checkout(floor, slotNumber - 1);
						
						foreColor(6); cout << "\n\n\t\t       Please click any key to Motorcycle again";Sleep(200);
						cout << "and [ESC] back to Menu Parcking !!!!"; Sleep(200);
					}while(getch() != 27);
				}break;
				
			case 4:
				{
					do
					{
						system("cls");
						
						p.printCheckoutInfo();
						
						getch();
                
                		goto a;
						
						foreColor(6); cout << "\n\n\t\t       Please click any key to Motorcycle again";Sleep(200);
						cout << "and [ESC] back to Menu Parcking !!!!"; Sleep(200);
					}while(getch() != 27);
				}break;
			
			case 5:
				{
					system("cls");
					
					foreColor(7); cout << "\n\n\n\n\t\t      <<<<< \2 Thank "; Sleep(200);
					cout << "you for used "; Sleep(200);
					cout << " my program, "; Sleep(200);
					cout << "I hope "; Sleep(200);
					cout << "you happy "; Sleep(200);
					cout << "with it \2>>>>>\n\n\n"; Sleep(200);
					
					getch();
					exit(0);
				}break;
			
			default:
				{
					foreColor(4); cout << "\n\t\t\t\t\t     Warning:: Invalid Option!!"; Sleep(200);
					getch();
				}break;
		}
		
	}while(true);
}