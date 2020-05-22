/*
    ====basic.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   4/14/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====basic.cpp====
*/

#include <iostream>
#include "basic.h"
using namespace std;

//Constructor
Basic::Basic()
{
    
}

//Destructor
Basic::~Basic()
{

}


void Basic::Print_Info()
{
    cout << "===PRINTING INFO BASIC===\n";
    Base::Print_Info();
    cout << "Cargo Capacity: " << cargo_cap << endl;
} //Prints Info

void Basic::Edit_Info()
{
    Print_Info();
    int choice = -1;
    while(choice != 0)
    {
        cout << "===EDITING INFO===\n";
        cout << "0. No changes. Exit.\n";
        cout << "1. Amount of baggage allowed.\n";
        cout << "2. Amount of passengers allowed.\n";
        cout << "3. Amount of Cargo allowed.\n";
        cout << "Enter the number of the desired request: ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 0:
                break;
            case 1:
                int NewAmount1;
                cout << "New Amount of Baggage Allowed (2-3): ";
                cin >> NewAmount1;
                cin.ignore();
                while(NewAmount1 > 3 || NewAmount1 < 2)
                {
                    cout << "Invalid amount. Pleas enter a new amount of baggage allowed (2-3):  ";
                    cin >> NewAmount1;
                    cin.ignore();
                }
                SetNo_Baggage(NewAmount1);
                cout << "Baggage changed.\n";
                break;
            case 2:
                int NewAmount2;
                cout << "New Amount of Passengers Allowed (2-4): ";
                cin >> NewAmount2;
                cin.ignore();
                while(NewAmount2 > 4 || NewAmount2 < 2)
                {
                    cout << "Invalid amount. Please enter a new amount of passengers allowed (2-4): ";
                    cin >> NewAmount2;
                    cin.ignore();
                }
                SetNo_Passengers(NewAmount2);
                cout << "Limit of Passsengers changed.\n";
                break;
            case 3:
                int NewAmount3;
                cout << "New Amount of Cargo Capacity (0-1): ";
                cin >> NewAmount3;
                cin.ignore();
                while(NewAmount3 > 1 || NewAmount3 < 0)
                {
                    cout << "Invalid amount. Please enter a new amount of cargo allowed (0-1): ";
                    cin >> NewAmount3;
                    cin.ignore();
                }
                SetCargo_Cap(NewAmount3);
                cout << "Cargo Capacity changed.\n";
                break;
            default:
                cout << "Unrecognied Input. Please enter the number of the desires request.\n";
                break;
        }
    }
}//Prompts user to edit info 
