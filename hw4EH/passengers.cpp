/*
    ====passengers.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====passengers.cpp====
*/

#include <iostream>
#include <iterator>
#include <iomanip>
#include <string>
#include <fstream>
#include "passenger.h"
#include "passengers.h"

void Passengers::Passenger_Info() //Ask user to add their name, create an ID, handicapped?, pets?, payment preference
{
    Passenger New_Passenger;
    string passenger_name;
    int passenger_id;
    string payment_preference;
    string handicapped;
    string pets;
    int default_rating;

    //Enter Passenger Name
    cout << "Enter Passenger Name: ";
    getline(cin, passenger_name);
    New_Passenger.SetPassenger_Name(passenger_name);

    //Enter Passenger ID
    cout << "Enter Passenger ID(6 digit value): ";
    cin >> passenger_id;
     cin.ignore();
     while(to_string(passenger_id).length() != 6)
     {
         cout << "Please enter a 6 value Passenger ID: ";
         cin >> passenger_id;
         cin.ignore();
     }
    while(Passengers::Is_ID_Taken(passenger_id))
    {
        cout << "Passenger ID is already taken. Please input another: ";
        cin >> passenger_id;
        cin.ignore();
    }
    New_Passenger.SetPassenger_ID(passenger_id);
    
    //Enter Payment Preference
    cout << "===PAYMENT PREFERENCE===\n";
    cout << "Enter Payment Preference ( Cash | Credit | Debit): ";
    getline(cin, payment_preference);
    New_Passenger.SetPayment_Preference(payment_preference);

    //Enter if pets
    cout << "Bringing Pets ( Yes | No ): ";
    cin.ignore();
    getline(cin, pets);
    New_Passenger.SetPets(pets);

    //Enter if handicapped
    cout << "Are You Handicapped ( Yes | No ): ";
    getline(cin, handicapped);
    New_Passenger.SetHandicapped(handicapped);
    
    Passengers.push_back(New_Passenger);
}

void Passengers::Modify_Passenger()
{
    int passenger_id;
    cout << "Enter Passenger ID: ";
    cin >> passenger_id;

    Passenger* Passenger_With_ID = FindPassengerByID(passenger_id);
    if(Passenger_With_ID)
    {
        int choice = -1;
        while(choice != 0)
        {
            cout << "===EDIT PASSENGER===\n";
            cout << "0. Exit\n";
            cout << "1. Passenger Name\n";
            cout << "2. Payment Preference\n";
            cout << "3. Pet Authorization\n";
            cout << "4. Handicap Authorization\n";
            cout << "Enter the number of description you would like to change: ";
            cin >> choice;
            cin.ignore();
            switch(choice)
            {
                case 0:
                    break;
                case 1:
                {
                    string New_Name;
                    cout << "Enter Passenger Name: ";
                    getline(cin, New_Name);
                    Passenger_With_ID->SetPassenger_Name(New_Name);
                    cout << "Driver Name Changed!\n";
                    break;
                }
                case 2:
                {
                    string New_Payment;
                    cout << "Enter Payment Preference: ";
                    getline(cin, New_Payment);
                    Passenger_With_ID->SetPayment_Preference(New_Payment);
                    cout << "Payment Preference Changed!\n";
                    break;   
                }
                case 3:
                {
                    string New_Pet;
                    cout << "Do You Plan on Bringing Pets? ( Yes |  No ): ";
                    getline(cin, New_Pet);
                    Passenger_With_ID->SetPets(New_Pet);
                    cout << "Authorization of Pets Changed!\n";
                    break;
                }
                case 4:
                {
                    string New_Handicap;
                    cout << "Allow Handicapped? ( Yes | No ): ";
                    getline(cin, New_Handicap);
                    Passenger_With_ID->SetHandicapped(New_Handicap);
                    cout << "Authorization of Handicapped Changed!\n";
                    break;
                }
                default:
                    cout << "Invaild Input. Please enter the number of the option.\n";
                    break;                
            }
        }
    }
    else
    {
        cout << "The Passenger ID is not found. Exiting...\n";
    }
    
}// Allows user to change Info 

void Passengers::Delete_Passenger()
{
    int Passenger_ID;
    bool RemovedPassenger = false;
    vector<Passenger>::iterator ptr;
    cout << "Enter Passenger ID: ";
    cin >> Passenger_ID;
    cin.ignore();
    for(ptr = Passengers.begin(); ptr < Passengers.end(); ptr++)
    {
        if(ptr->GetPassenger_ID() == Passenger_ID)
        {
            Passengers.erase(ptr);
            cout << "Passenger Removed!\n";
            RemovedPassenger = true;
        }
    }
    if(!RemovedPassenger)
    {
        cout << "Unable to find Passenger...\n";
    }
}// Removes Passengers from data

void Passengers::Print_All_Passengers()
{
    cout << "===PRINTING ALL PASSENGERS===\n";
    cout << "\tPassenger Name\t\tPassenger ID\t\tPayment Preference\t\tPets\t\tHandicapped\n";
    vector<Passenger>::iterator ptr;
    for(ptr = Passengers.begin(); ptr < Passengers.end(); ptr++)
    {
        ptr->Print_Info();
    } 
}// Print the Info of all the Passengers

void Passengers::Print_Single_Driver_Info()
{
    int Passenger_ID;
    cout  << "Enter Passenger ID: ";
    cin >> Passenger_ID;
    Print_Single_Driver_Info(Passenger_ID);
}
void Passengers::Print_Single_Driver_Info(int Passenger_ID)
{
    Passenger* Passenger_With_ID = FindPassengerByID(Passenger_ID);
    if(Passenger_With_ID)
    {
        cout << "\tPassenger Name\t\tPassenger ID\t\tPayment Preference\t\tPets\t\tHandicapped\n";
        Passenger_With_ID->Print_Info();
    }
    else
    {
        cout << "Passenger ID is invalid or can't be found.\n";
    }
    
}
bool Passengers::Is_ID_Taken(int Passenger_ID)
{
    vector<Passenger>::iterator ptr;
    for(ptr = Passengers.begin(); ptr < Passengers.end(); ptr++)
    {
        if(ptr->GetPassenger_ID() == Passenger_ID)
        {
            return true;
        }
    }
    return false;
}

void Passengers::Load_Data()
{
    Passengers.clear();
    ifstream input;
    int All;
    input.open("passengers.dat");
    input >> All;
    input.ignore();
    for(int n = 0; n < All; n++)
    {
        Passenger New_Passengers;
        string passenger_name;
        int passenger_id;
        string payment_preference;
        string handicapped;
        string pets;
        int default_rating;
        input >> passenger_id;
        input >> default_rating;
        cin.ignore();
        getline(input, passenger_name);
        cin.ignore();
        getline(input, pets);
        cin.ignore();
        getline(input, handicapped);
        cin.ignore();
        getline(input, payment_preference);

        New_Passengers.SetPassenger_Name(passenger_name);
        New_Passengers.SetPassenger_ID(passenger_id);
        New_Passengers.SetDefault_Rating(default_rating);
        New_Passengers.SetHandicapped(handicapped);
        New_Passengers.SetPayment_Preference(payment_preference);
        New_Passengers.SetPets(pets);

        Passengers.push_back(New_Passengers);
    
    }
    input.close();
}
void Passengers::Save_Data()
{
    ofstream output;
    output.open("passengers.dat");
    vector<Passenger>::iterator ptr;
    output << Passengers.size() << endl;
    for(ptr = Passengers.begin(); ptr < Passengers.end(); ptr++)
    {
        output << "\t" << ptr->GetPassenger_Name() << "\t\t" << ptr->GetPassenger_ID() << "\t\t" << ptr->GetPayment_Preference() << "\t\t" << ptr->GetPets() << "\t\t" << ptr->GetHandicapped() << endl;
    }
    output.close();
}// Saves the data of each passenger into a data file 

void Passengers::Print_All_Rides_Passengers()
{

}//Prints all the history rides of the Passenger

void Passengers::Search_Passenger()
{
    string Passenger_Name;
    cout << "Enter The Name of Passenger: ";
    cin >> Passenger_Name;
    Search_Passenger(Passenger_Name);
}//Inputs the name of the passenger

void Passengers::Search_Passenger(string Passenger_Name)
{
    Passenger* Passenger_With_Name = FindPassengerByName(Passenger_Name);
    if(Passenger_With_Name)
    {
        cout << "\tPassenger Name\t\tPassenger ID\t\tPayment Preference\t\tPets\t\tHandicapped\n";
        Passenger_With_Name->Print_Info();
    }
    else
    {
        cout << "Passenger Name is not found.\n";
    }
    
}//Searches for the same passenger name and prints out the info 

Passenger* Passengers::FindPassengerByID(int Passenger_ID)
{
    vector<Passenger>::iterator ptr;
    for(ptr = Passengers.begin(); ptr < Passengers.end(); ptr++)
    {
        if(ptr->GetPassenger_ID() == Passenger_ID)
        {
            return &(*ptr);        }
    }
    return nullptr;
}//Searches for the passengers ID and dertermines if there is a similar one


Passenger* Passengers::FindPassengerByName(string Passenger_Name)
{
    vector<Passenger>::iterator ptr;
    for(ptr = Passengers.begin(); ptr < Passengers.end(); ptr++)
    {
        if(ptr->GetPassenger_Name() == Passenger_Name)
        {
            return &(*ptr);      
        }
    }
    return nullptr;
}