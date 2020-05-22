/*
    ====rides.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====rides.h====
*/

#ifndef rides_h
#define rides_h

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "ride.h"
#include "drivers.h"
#include "passengers.h"
using namespace std;

class Drivers;

class Rides
{
    private:
        vector<Ride> Rides;

    public:
        void Add_Ride(Drivers* DRIVERS); //Ask user for the requested time to be picked up and dropped off and depature and destination, is Driver Avaliable(bool), number of passengers(int), Driver ID(List). Check the values if they are longe
        void Modify_Ride(Drivers* DRIVERS); // Ask user for the Ride ID and to display a menu of options to choose from. For instance, 
        void Delete_Ride();//Ask user for Ride ID
        void Cancel_Ride(); //Ask user for Ride ID and to confirm whether to cancel. Will search for the Ride and change the status to cancelled
        Ride* FindRideByID(int Ride_ID);
        
        vector<Ride*> Find_Ride_By_Driver_ID(int Driver_ID);
        vector<Ride*> Find_Ride_By_Status(int status);
        void Print_All_Rides(); //Print all rides that are requested or ongoing
        void Print_Single_Ride_Info(); //Ask user to input the Ride ID
        void Print_Single_Ride_Info(int Ride_ID); //Using Print_Single_Ride_Info(), Find the Ride information and print info
        void Print_Rides_Passenger(Passengers* PASSENGERS);

        void Load_Data(); //Loads data from disk
        void Save_Data(); //Saves data from disk
        void Print_All_Rides_Driver(int Driver_ID); //Ask user for user ID
        void Print_All_Rides_Driver();
        bool Check_If_Driver_Available(int Driver_ID, time_t Pickup_Time, time_t Dropoff_Time);
        void Set_Number_of_Passengers(int Party_Size);
        bool Is_ID_Taken(int Ride_ID);



};

#endif