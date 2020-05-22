/*
    ====main.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
DESCRIPTION: Simulated Uber Model Program
Copyright (c) 2020 Edwin Hernandez
    ====main.cpp====
*/
#include <iostream> 
#include <string>
#include "drivers.h"
#include "passengers.h"
#include "rides.h"
using namespace std;

Drivers DRIVERS;
Passengers PASSENGERS;
Rides RIDES;

void PrintHeader();
void Load();
void Save();


int main()
{   
   int input;

    
    do{
        PrintHeader();
        cout << "Enter the number of choice and press enter: ";
        cin >> input;
        cin.ignore();
        switch(input)
        {
            case 0:
                Save();
                cout << "\n";
                cout << "Thank You For Trying Eagle Lift!\n";
                    break;
            case 1:
                DRIVERS.Driver_Info();
                break;
            case 2:
                DRIVERS.Delete_Driver();
                    break;
            case 3:
                DRIVERS.Modify_Driver();
                break;
            case 4:
                DRIVERS.Search_Driver();
                break;
            case 5:
                DRIVERS.Print_All_Drivers();
                break;
            case 6:
                DRIVERS.Print_Single_Driver_Info();
                break;
            case 7:
                RIDES.Print_All_Rides_Driver();
                break;
            case 8:
                PASSENGERS.Passenger_Info();
                break;
            case 9:
                PASSENGERS.Delete_Passenger();
                break;
            case 10:
                PASSENGERS.Modify_Passenger();
                break;
            case 11:
                PASSENGERS.Search_Passenger();
                break;
            case 12:
                PASSENGERS.Print_All_Passengers();
                break;
            case 13:
                RIDES.Add_Ride(&DRIVERS);
                break;
            case 14:
                RIDES.Delete_Ride();
                break;
            case 15:
                RIDES.Cancel_Ride();
                break;
            case 16:
                RIDES.Modify_Ride(&DRIVERS);
                break;
            case 17:
                RIDES.Print_All_Rides();
                break;
            case 18: 
                Save();
                break;
            case 19:
                Load();
                break;
            default: 
                cout << "Please enter the number of the option you would like.\n";
                break; 

        }
    }while (input != 0);
    
    return 0;
}

void Load()
{
    DRIVERS.Load_Data();
    PASSENGERS.Load_Data();
    RIDES.Load_Data();
}
void Save()
{
    DRIVERS.Save_Data();
    PASSENGERS.Save_Data();
    RIDES.Save_Data();
}
void PrintHeader()
{   
    
    cout << "Homework 3 - Mean Green EagleLift" << endl;
    cout << "Author: Edwin Hernandez" << endl;;
    cout << "Course: CSCE 1040" << endl;
    cout << "Email: Edwinhernandez2@my.unt.edu" << endl;
    cout << "\n";
    cout << "\n";
    
    cout << "===WELCOME TO EAGLE LIFT===" << endl;
    cout << "\n";
    cout << "1. Add Driver\n";
    cout << "2. Remove Driver\n";
    cout << "3. Modify Driver\n";
    cout << "4. Search/Find Driver\n";
    cout << "5. Print List of Drivers\n";
    cout << "6. Print Detail of Driver\n";
    cout << "7. Print All Rides Given By Driver\n";
    cout << "\n";
    cout << "8. Add Passenger\n";
    cout << "9. Remove Passenger\n";
    cout << "10. Modify Passenger\n";
    cout << "11. Search/Find Passenger\n";
    cout << "12. Print List of Passengers\n";
    cout << "\n";
    cout << "13. Add Ride\n";
    cout << "14. Remove Ride\n";
    cout << "15. Cancel Particular Ride\n";
    cout << "16. Modify Ride\n";
    cout << "17. Display All Rides\n";  
    cout <<"\n";
    cout << "18. Save\n";
    cout << "19. Load\n"; 
    cout << "\n";
    cout << "0. Save and Quit\n";
}