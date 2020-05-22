/*
    ====luxury.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   4/14/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====luxury.cpp====
*/

#include <iostream>
#include "luxury.h"
using namespace std;

//Constructor
Luxury::Luxury()
{   
    SetNo_Passengers(0);
}

//Destructor
Luxury::~Luxury()
{

}

string Luxury::GetLuxuryType_As_String()
{
    switch(LuxuryType)
    {
        case Mercedes:
            return "Mercedes";
            break;
        case Tesla:
            return "Tesla";
            break;
        case Porsche:
            return "Porsche";
            break;
        case GTR:
            return "GTR";
            break;
        default:
            cout << " ";
            break;
    }
} //Returns the string that says the Luxury Type

void Luxury::SetLuxuryType(Luxury_Type LuxuryType_)
{
    LuxuryType = LuxuryType_;
}

void Luxury::SetLuxuryType()
{
    int user_choice;
    do{
        cout << "0. Mercedes\n";
        cout << "1. Tesla\n";
        cout << "2. Porsche\n";
        cout << "3. GTR\n";
        cout << "Please enter the type of group you fit with: ";
        cin >> user_choice;
        cin.ignore();
    }while(user_choice < 0 || user_choice > 3);
    LuxuryType = static_cast<Luxury_Type>(user_choice);
}//Requests the Luxury Type

void Luxury::Print_Info()
{
    Base::Print_Info();
    cout << "Luxury Type: " << GetLuxuryType_As_String() << endl;
} //Prints Info

void Luxury::Edit_Info()
{
    Print_Info();
    int choice = -1;
    while(choice != 0)
    {
        cout << "===EDITING INFO===\n";
        cout << "0. No changes. Exit.\n";
        cout << "1. Amount of passengers allowed.\n";
        cout << "2. Change Luxury Type.\n";
        cout << "Enter the number of the desired request: ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 0:
                break;
            case 1:
                int NewAmount2;
                cout << "New Amount of Passengers Allowed (1 or 2): ";
                cin >> NewAmount2;
                cin.ignore();
                while(NewAmount2 < 1 || NewAmount2 > 2)
                {
                    cout << "Invalid amount. Please enter a new amount of passengers allowed (1 or 2): ";
                    cin >> NewAmount2;
                    cin.ignore();
                }
                SetNo_Passengers(NewAmount2);
                cout << "Limit of Passsengers changed.\n";
                break;
            case 2:
                SetLuxuryType();
                break;
            default:
                cout << "Unrecognied Input. Please enter the number of the desires request.\n";
                break;
        }
    }
} //Prompts user to edit info



