/*
    ====rides.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====rides.cpp====
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "rides.h"

time_t Get_Time_From_User()
{
    struct tm time_box;
    int Time_Year, Time_Month, Time_Day;
    int Time_Hour, Time_Min;
    cout << "Enter year: ";
    cin >> Time_Year;
    cin.ignore();
    time_box.tm_year = Time_Year-1900;
    cout << "Enter month: ";
    cin >> Time_Month;
    cin.ignore();
    time_box.tm_mon = Time_Month - 1;
    cout << "Enter day: ";
    cin >> Time_Day;
    cin.ignore();
    time_box.tm_mday = Time_Day;
    cout << "Enter hour (0-23): ";
    cin >> Time_Hour;
    cin.ignore();
    time_box.tm_hour = Time_Hour;
    cout << "Enter minute (0-59): ";
    cin >> Time_Min;
    cin.ignore();
    time_box.tm_min = Time_Min;
    time_box.tm_sec = 0;
    
    return mktime(&time_box);
}
void Rides::Add_Ride(Drivers* DRIVERS)
{
    Ride New_Ride;
    int ride_id;
    int driver_id;
    int party_size;
    string pets;
    string handicapped;
    vector<int> Driver_IDs; 
    time_t pickup_time; //Start time (date-time)
    time_t dropoff_time; //End time (date-time)
    string pickup_location; //Represents where the driver departed from
    string dropoff_location; //Represents where the driver arrives at
    int status = -1;
    int temp_id = -1;
    cout << "===CREATING NEW RIDE===\n";
    //Enter Ride ID
    cout << "Enter Ride ID (8 digits): ";
    cin >> ride_id;
    cin.ignore();
    while(to_string(ride_id).length() != 8)
    {
        cout << "Please enter a 8 digit Ride ID: ";
        cin >> ride_id;
        cin.ignore();
    }
    
    while(Rides::Is_ID_Taken(ride_id))
    {
        cout << "Ride ID is already taken. Enter another Ride ID: ";
        cin >> ride_id;
        cin.ignore();
    }
    New_Ride.SetRide_ID(ride_id);
    //Enter If handicapped
    cout << "Are you or anyone handicapped ( Yes | No )?\n";
    getline(cin,handicapped);
    //Enter if any Pets
    cout << "Are you bringing any pets (Yes | No )?\n";
    getline(cin,pets);
    //Enter Pickup_Location
    cout << "Enter your Pickup Location: ";
    getline(cin,pickup_location);
    New_Ride.SetPickup_Location(pickup_location);
    //Processing Pickup_Time
    cout << "Processing your Pickup Time (Date/Time)...\n";
    pickup_time = Get_Time_From_User();
    New_Ride.SetPickup_Time(pickup_time);
    //Enter Dropoff_Location
    cout << "Enter your Dropoff Location: ";
    getline(cin,dropoff_location);
    New_Ride.SetDropoff_Location(dropoff_location);
    //Processing Dropoff_Time
    cout << "Processing your Dropoff Time (Date/Time)...\n";
    dropoff_time = Get_Time_From_User();
    New_Ride.SetDropoff_Time(dropoff_time);
    
    //Enter Driver ID
    cout << "Enter Driver ID: ";
    cin >> driver_id;
    cin.ignore();
    while(!DRIVERS->Is_ID_Taken(driver_id))
    {
        cout << "No Driver with thi ID. Please enter another Driver ID: ";
        cin >> driver_id;
        cin.ignore();
    }
    while(!Check_If_Driver_Available(driver_id, pickup_time, dropoff_time))
    {
        cout << "Driver is unavailable at this time. Please enter another Driver ID: ";
        cin >> driver_id;
        cin.ignore();   
    }
    New_Ride.SetDriver_ID(driver_id);

    //Enter Party_Size
    cout << "Number of Passengers: ";
    cin >> party_size;
    cin.ignore();
    while(!DRIVERS->Does_Driver_Have_Enough_Seats(driver_id, party_size))
    {
        cout << "There are not enough seats. Please  enter a smaller number: ";
        cin >> party_size;
        cin.ignore();
    }
    New_Ride.SetParty_Size(party_size);
    
    //Enter Status
    while(status > 2 || status < 0)
    {
        cout << "===STATUS OF RIDE===\n";
        cout << "0. Canceled\n";
        cout << "1. Active\n";
        cout << "2. Completed\n";
        cout << "Enter the status of the ride: ";
        cin >> status;
        cin.ignore();
        switch (status)
        {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        default:
            cout << "Enter the number of the status\n";
            break;
        }
    }
    New_Ride.SetStatus(status);

    Rides.push_back(New_Ride);
    
}
void Rides::Modify_Ride(Drivers* DRIVERS)
{
    int ride_id;
    
    cout << "Enter Ride ID: ";
    cin >> ride_id;
    cin.ignore();

    Ride* Ride_With_ID = FindRideByID(ride_id);
    if(Ride_With_ID)
    {
        Ride_With_ID->Print_Info();
        int choice = -1;
        while(choice != 0)
        {
            cout << "===EDITING RIDE===\n";
            cout << "0. Exit\n";
            cout << "1. Change Pickup Location\n";
            cout << "2. Change Dropoff Location\n";
            cout << "3. Reset Pickup Time\n";
            cout << "4. Reset Dropoff Time\n";
            cout << "5. Number of Passengers\n";
            cout << "6. Status\n";
            cout << "7. Reset Driver\n";
            cout << "Choose a number of your choice: ";
            cin >> choice;
            cin.ignore();
            switch(choice)
            {
                case 0:
                {
                    //Exit
                    break;
                }
                case 1:
                {
                    //Change Pickup Location
                    string pickup_location;
                    cout << "Change your pickup location: ";
                    getline(cin,pickup_location);
                    Ride_With_ID->SetPickup_Location(pickup_location);
                    cout << "Pickup Location Changed!\n";
                    break;
                }
                case 2:
                {
                    //Change Dropoff Location
                    string dropoff_location;
                    cout << "Chnage your dropoff location: ";
                    getline(cin, dropoff_location);
                    Ride_With_ID->SetDropoff_Location(dropoff_location);
                    cout << "Dropoff Location Changed!\n";
                    break;
                }
                case 3:
                {
                    //Reset Pickup Time
                    time_t pickup_time;
                    cout << "Change pickup time.\n";
                    pickup_time = Get_Time_From_User();
                    Ride_With_ID->SetPickup_Time(pickup_time);
                    cout << "Time Changed!\n";
                    break;
                }
                case 4:
                {
                    //Reset Dropoff Time
                    time_t dropoff_time;
                    cout << "Change dropoff time.\n";
                    dropoff_time = Get_Time_From_User();
                    Ride_With_ID->SetDropoff_Time(dropoff_time);
                    cout << "Time Changed!\n";
                    break;
                }
                case 5:
                {
                    //Change Number of Passengers
                    int party_size;
                    cout << "Change number of passengers: ";
                    cin >> party_size;
                    cin.ignore();
                    while (!DRIVERS->Does_Driver_Have_Enough_Seats(Ride_With_ID->GetDriver_ID(), party_size))
                    {
                        cout << "Not enough seats for your request. Please enter a smaller number: ";
                        cin >> party_size;
                        cin.ignore();
                    }
                    Ride_With_ID->SetParty_Size(party_size);
                    break;
                }
                case 6:
                { 
                    //Status
                    int status = -1;
                    while(status > 2 || status < 0)
                    {
                        cout << "===STATUS OF RIDE===\n";
                        cout << "0. Canceled\n";
                        cout << "1. Active\n";
                        cout << "2. Completed\n";
                        cout << "Enter the status of the ride: ";
                        cin >> status;
                        cin.ignore();
                        switch (status)
                        {
                        case 0:
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Enter the number of the status\n";
                            break;
                        }
                    }
                    Ride_With_ID->SetStatus(status);
                    break;
                }    
            }
        }
    }
}
void Rides::Delete_Ride()
{
    int ride_id;
    bool removed_ride = false;
    vector<Ride>::iterator ptr;
    cout << "Enter Ride ID: ";
    cin >> ride_id;
    cin.ignore();
    for(ptr = Rides.begin(); ptr < Rides.end(); ptr++)
    {
        if(ptr->GetRide_ID() == ride_id)
        {
            Rides.erase(ptr);
            cout << "Ride Removed!\n";
            removed_ride = true;
        }
    }
    if(!removed_ride)
    {
        cout << "The ID given can not find the ride.\n";
    }
}

void Rides::Cancel_Ride()
{
    int ride_id;
    bool removed_ride = false;
    vector<Ride>::iterator ptr;
    cout << "Enter Ride ID: ";
    cin >> ride_id;
    cin.ignore();
    for(ptr = Rides.begin(); ptr < Rides.end(); ptr++)
    {
        if(ptr->GetRide_ID() == ride_id)
        {
            ptr->SetStatus(0);
            cout << "Cancelled Ride.\n";
            removed_ride = true;
        }
    }
    if(!removed_ride)
    {
        cout << "The ID given can not find the ride.\n";
    }
}
Ride* Rides::FindRideByID(int Ride_ID)
{
    vector<Ride>::iterator ptr;
    for(ptr = Rides.begin(); ptr < Rides.end(); ptr++)
    {
        if(ptr->GetRide_ID() == Ride_ID)
        {
            return &(*ptr);
        }
    }
    cout << "Ride with given ID can not be found.\n";
    return nullptr;
}

vector<Ride*> Rides::Find_Ride_By_Driver_ID(int Driver_ID)
{
    vector<Ride*> vec;
    vector<Ride>::iterator ptr;
    for(ptr = Rides.begin(); ptr < Rides.end(); ptr++)
    {
        if(ptr->GetDriver_ID() == Driver_ID)
        {
            vec.push_back(&(*ptr));
        }
    }
    cout << "Driver ID was not found.\n";
    return vec;
}//Searches for rides with driver ID

vector<Ride*> Rides::Find_Ride_By_Status(int status)
{
    vector<Ride*> vec;
    vector<Ride>::iterator ptr;
    for(ptr = Rides.begin(); ptr < Rides.end(); ptr++)
    {
        if(ptr->GetStatus() == status)
        {
            vec.push_back(&(*ptr));
        }
    }
    if(vec.size() == 0)
    {
        cout << "Ride cannot be found.\n";
    }
    return vec;
}//Searches for rides with status

void Rides::Print_All_Rides()
{
    cout << "===PRINTING ALL RIDES===\n";
    vector<Ride>::iterator ptr;
    for(ptr = Rides.begin(); ptr < Rides.end(); ptr++)
    {
        ptr->Print_Info();
    }
}//Prints all info for each ride

void Rides::Print_Single_Ride_Info()
{
    int ride_id;
    cout << "Enter Ride ID: ";
    cin >> ride_id;
    Print_Single_Ride_Info(ride_id);
}
void Rides::Print_Single_Ride_Info(int Ride_ID)
{
    Ride* Ride_With_ID = FindRideByID(Ride_ID);
    if(Ride_With_ID)
    {
        Ride_With_ID->Print_Info();
    }
    else
    {
        cout << "Ride ID cannot be found.\n";
    }
}//Printing every collection for the Ride 

void Rides::Load_Data()
{
    Rides.clear();
    ifstream input;
    int All;
    input.open("rides.dat");
    input >> All;
    input.ignore();
    if(input.is_open())
    {
        for(int n = 0; n < All; n++)
        {
            Ride New_Ride;
            int ride_id; //Generates a 6 digit ID for the ride (use rand)
            int driver_id;
            vector<int> driver_ids;
            string pickup_location; //Represents where the driver departed from
            string dropoff_location; //Represents where the driver arrives at
            time_t pickup_time; //Start time (date-time)
            time_t dropoff_time; //End time (date-time)
            int party_size; //number of passengers 
            string pets; //Will there be a pet on board?
            int status; //Create an integer base (0= cancelled | 1 = active | 2 = completed)
            int rating_by_customer; //Passenger gives a rating to the driver
            
            input >> ride_id;
            input.ignore();
            input >> driver_id;
            input.ignore();
            input >> pickup_time;
            input >> dropoff_time;
            input.ignore();
            getline(input, pickup_location);
            getline(input, dropoff_location);
            input >> party_size;
            input >> status;
            input.ignore();

            getline(input, pets);
            
            New_Ride.SetDriver_ID(driver_id);
            New_Ride.SetDropoff_Location(dropoff_location);
            New_Ride.SetDropoff_Time(dropoff_time);
            New_Ride.SetParty_Size(party_size);
            New_Ride.SetPets(pets);
            New_Ride.SetPickup_Location(pickup_location);
            New_Ride.SetPickup_Time(pickup_time);
            New_Ride.SetRide_ID(ride_id);
            New_Ride.SetStatus(status);

            Rides.push_back(New_Ride);
        }
        input.close();
    }

}//Loads saved data

void Rides::Save_Data()
{
    ofstream output;
    output.open("rides.dat");
    vector<Ride>::iterator ptr;
    output << Rides.size() << endl;
    for(ptr = Rides.begin(); ptr < Rides.end(); ptr++)
    {
        output << ptr->GetRide_ID() << endl;
        output << ptr->GetDriver_ID() << endl;
        output << ptr->GetStatus() << endl;
        output << ptr->GetPickup_Location() << endl;
        output << ptr->GetPickup_Time() << endl;
        output << ptr->GetDropoff_Location() << endl;
        output << ptr->GetDropoff_Time() << endl;
        output << ptr->GetParty_Size() << endl;
        output << ptr->GetPets() << endl;
        output << ptr->GetRating_By_Customer() << endl;
    }
    output.close();
}//Saves data of rides

void Rides::Print_All_Rides_Driver(int Driver_ID)
{
    cout << "==PRINTING ALL RIDES===\n";
    vector<Ride*> List_OF_Rides_With_Status = Find_Ride_By_Driver_ID(Driver_ID);
    vector<Ride*>::iterator ptr;
    for (ptr = List_OF_Rides_With_Status.begin(); ptr < List_OF_Rides_With_Status.end(); ptr++)
    {
        (*ptr)->Print_Info();
    }

}//Prints All rides of Driver

void Rides::Print_All_Rides_Driver()
{
    int driver_id;
    cout << "Enter Driver ID: ";
    cin >> driver_id;
    cin.ignore();
    Print_All_Rides_Driver(driver_id);
}


bool Rides::Check_If_Driver_Available(int Driver_ID, time_t Pickup_Time, time_t Dropoff_Time)
{
    vector<Ride*> List_Of_Rides_With_Driver = Find_Ride_By_Driver_ID(Driver_ID);
    vector<Ride*>::iterator ptr;
    for(ptr = List_Of_Rides_With_Driver.begin(); ptr < List_Of_Rides_With_Driver.end(); ptr++)
    {
        if((Pickup_Time <= (*ptr)->GetDropoff_Time()) && ((*ptr)->GetPickup_Time() <= Dropoff_Time))
        {
            return false;
        }
    }
    return true;
}

bool Rides::Is_ID_Taken(int Ride_ID)
{
    vector<Ride>::iterator ptr;
    for(ptr = Rides.begin(); ptr < Rides.end(); ptr++)
    {
        if(ptr->GetRide_ID() == Ride_ID)
        {
            return true;
        }
    }
    return false;
}

