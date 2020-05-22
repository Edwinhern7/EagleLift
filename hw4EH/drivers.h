/*
    ====drivers.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====drivers.h====
*/

#ifndef drivers_h
#define drivers_h

#include <iostream>
#include <string>
#include <vector>
#include "driver.h"
#include "base.h"
using namespace std;

class Drivers
{
    private:
        vector<Driver> Drivers;
        vector<Base*> Bases;
    public:
    
        //virtual ~Drivers(); 

        void Driver_Info(); //Ask user to create a driver name, ID, vehicle type, allow pets, and handicapped
        void Modify_Driver(); //Ask user for name and ID and list what they want to modify, then allow them and save data
        void Delete_Driver(); //Ask user for name and ID and ask why do you want to delete user and confirm; Save data
        void Print_All_Drivers(); //Ask user for driver's name and type of vehicle
        void Print_Single_Driver_Info(); //Ask user what entity they want and Print the details
        void Print_Single_Driver_Info(int Driver_ID); //Displays the driver's informations in an organized table 
        bool Does_Driver_Have_Enough_Seats(int Driver_ID, int Num_Seats); //Search for the Driver's in its collection w/ Driver_ID and checks the seat capacity, returning the result
        bool Is_ID_Taken(int Driver_ID); //Checks all of the Drivers to see if the ID is already assigned with a Driver
        void Load_Data(); //Loads data from disk
        void Save_Data(); //Saves data from disk
        void Print_All_Rides_Driver(); //Ask user for name and user ID
        void Search_Driver();
        void Search_Driver(string Driver_Name); //Type name and vehicle type 
        Driver* FindDriverByID(int Driver_ID); //returns all drivers with the given Driver ID
        Driver* FindDriverByName(string Driver_Name); // Returns all Driver with given Driver Name

        Base* FindDriverType_By_ID(int ID);
        string CheckDriver_Type(int ID);
        bool Is_Backup_ID_Taken(int ID);
        bool Is_DriverType_A_Type(int ID, int DriverType);
        //Create a function that allows to Delete Driver Type Info for specific user
        //Create a function that saves the Driver Type Info for specific user
        //Create a function that loads the previous Driver Type Info for each user
        //Add the Print Info function to print all drivers info 
        //Create a function to find user's driver type by driver ID
        
};

#endif