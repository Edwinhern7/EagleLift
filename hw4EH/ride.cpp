/*
    ====ride.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====ride.cpp====
*/

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "ride.h"

void Ride::Print_Info()
{
    cout << "\tRIDE ID\t\tPASSENGERS\t\tSTATUS\n";
    cout << "\t" << ride_id << "\t\t" << party_size << "\t\t";
    switch(status)
    {
        case 0:
            cout << "Cancelled\n";
            break;
        case 1:
            cout << "Active\n";
            break;
        case 2:
            cout << "Completed\n";
            break;
    }
    //Print Drivers Info
    cout << "\tDRIVER ID\n";
    for(vector<int>::iterator i = driver_ids.begin(); i < driver_ids.end(); i++)
    {
        cout << *i << endl;
    }
    cout << "\n";

    //Print Pickup/Dropofff Info
    cout << "\tDEPATURE: " << pickup_location << "\t\t" << ctime(&pickup_time) << endl;
    cout << "\n";
    cout << "\tARRIVAL: " << dropoff_location << "\t\t" << ctime(&dropoff_time) << endl;
}

bool Ride::Is_Driver_Busy(int Driver_ID)
{
    vector<int>::iterator ptr;
    for(ptr = driver_ids.begin(); ptr < driver_ids.end(); ptr++)
    {
        if(*ptr == Driver_ID)
        {
            return true;
        }
    }
    return false;

}
