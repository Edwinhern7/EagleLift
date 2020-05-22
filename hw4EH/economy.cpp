/*
    ====economy.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   4/14/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====economy.cpp====
*/

#include <iostream>
#include "economy.h"
using namespace std;

//Constructor
Economy::Economy()
{
    SetNo_Baggage(0);
    SetNo_Passengers(0);
}
//Destructor
Economy::~Economy()
{

}

//Specific constructor
Economy::Economy(int No_Passengers, int No_Baggage)
{
    SetNo_Passengers(No_Passengers);
    SetNo_Baggage(No_Baggage);
}

 
void Economy::Print_Info()
{
    cout << "===PRINTING INFO===\n";
    Base::Print_Info();
    
}//Prints the info from Base to Economy 

void Economy::Edit_Info()
{
    Print_Info();
    int choice = -1;
    while(choice != 0)
    {
        cout << "===EDITING INFO===\n";
        cout << "0. No changes. Exit.\n";
        cout << "1. Amount of baggage allowed.\n";
        cout << "2. Amount of passengers allowed.\n";
        cout << "Enter the number of the desired request: ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 0:
                break;
            case 1:
                int NewAmount1;
                cout << "New Amount of Baggage Allowed (0-2): ";
                cin >> NewAmount1;
                cin.ignore();
                while(NewAmount1 > 2 || NewAmount1 < 0)
                {
                    cout << "Invalid amount. Pleas enter a new amount of baggage allowed (0-2):  ";
                    cin >> NewAmount1;
                    cin.ignore();
                }
                SetNo_Baggage(NewAmount1);
                cout << "Baggage changed.\n";
                break;
            case 2:
                int NewAmount2;
                cout << "New Amount of Passengers Allowed (0-2): ";
                cin >> NewAmount2;
                cin.ignore();
                while(NewAmount2 > 2 || NewAmount2 < 0)
                {
                    cout << "Invalid amount. Please enter a new amount of passengers allowed (0-2): ";
                    cin >> NewAmount2;
                    cin.ignore();
                }
                SetNo_Passengers(NewAmount2);
                cout << "Limit of Passsengers changed.\n";
                break;
            default:
                cout << "Unrecognied Input. Please enter the number of the desires request.\n";
                break;
        }
    }
} //Prompts user to edit info 





