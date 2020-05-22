/*
    ====group.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   4/14/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====group.cpp====
*/

#include <iostream>
#include "group.h"
using namespace std;

//Constructor
Group::Group()
{
    
}

//Destructor
Group::~Group()
{

}

string Group::GetGroupType_As_String()
{
    switch(GroupType)
    {
        case Limo:
            return "Limo";
            break;
        case PartyBus:
            return "Party Bus";
            break;
        default:
            return "";
            break;
    }
} //Returns the string that says the GroupType

void Group::SetGroupType(Group_Type Group_Type)
{
    GroupType = Group_Type;
}

void Group::SetGroupType()
{
    int user_choice;
    do{
        cout << "0. Limo\n";
        cout << "1. Party Bus\n";
        cout << "Please enter the type of group you fit with: ";
        cin >> user_choice;
        cin.ignore();
    }while (user_choice > 1 || user_choice < 0);
    GroupType = static_cast<Group_Type>(user_choice);
}// Prompts the user and returns the GroupType from user

void Group::Print_Info()
{
    Base::Print_Info();
    cout << "Group Type: " << GetGroupType_As_String() << endl;
} //Prints Info

void Group::Edit_Info()
{
    Print_Info();
    int choice = -1;
    while(choice != 0)
    {
        cout << "===EDITING INFO===\n";
        cout << "0. No changes. Exit.\n";
        cout << "1. Amount of baggage allowed.\n";
        cout << "2. Amount of passengers allowed.\n";
        cout << "3. Change Group Type.\n";
        cout << "Enter the number of the desired request: ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 0:
                break;
            case 1:
                int NewAmount1;
                cout << "New Amount of Baggage Allowed (4-6): ";
                cin >> NewAmount1;
                cin.ignore();
                while(NewAmount1 > 6 || NewAmount1 < 4)
                {
                    cout << "Invalid amount. Pleas enter a new amount of baggage allowed (4-6):  ";
                    cin >> NewAmount1;
                    cin.ignore();
                }
                SetNo_Baggage(NewAmount1);
                cout << "Baggage changed.\n";
                break;
            case 2:
                int NewAmount2;
                cout << "New Amount of Passengers Allowed (5-7): ";
                cin >> NewAmount2;
                cin.ignore();
                while(NewAmount2 > 7 || NewAmount2 < 5)
                {
                    cout << "Invalid amount. Please enter a new amount of passengers allowed (5-7): ";
                    cin >> NewAmount2;
                    cin.ignore();
                }
                SetNo_Passengers(NewAmount2);
                cout << "Limit of Passsengers changed.\n";
                break;
            case 3:
                SetGroupType();
                break;
            default:
                cout << "Unrecognied Input. Please enter the number of the desires request.\n";
                break;
        }
    }
}//Prompts user to edit info

