/*
    ====ride.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====ride.h====
*/

#ifndef ride_h
#define ride_h
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "driver.h"
using namespace std;

class Ride
{
    private:
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
        
    public:
        //Setters
        void SetDriver_ID(int Driver_ID)
        {
            driver_id = Driver_ID;
        };
        void SetRide_ID(int Ride_ID)
        {
            ride_id = Ride_ID;
        };
        void SetPickup_Location(string Pickup_Location)
        {
            pickup_location = Pickup_Location;
        };
        void SetDropoff_Location(string Dropoff_Location)
        {
            dropoff_location = Dropoff_Location;
        };
        void SetPickup_Time(time_t Pickup_Time)
        {
            pickup_time = Pickup_Time;
        };
        void SetDropoff_Time(time_t Dropoff_Time)
        {
            dropoff_time = Dropoff_Time;
        };
        void SetParty_Size(int Party_Size)
        {
            party_size = Party_Size;
        };
        void SetStatus(int Status)
        {
            status = Status;
        };
        void SetRating_By_Customer(int Rating_By_Customer)
        {
            rating_by_customer = Rating_By_Customer;
        };
        void SetPets(string Pets)
        {
            pets = Pets;
        };
        void SetDriver_IDs(vector<int> ids)
        {
            driver_ids = ids;
        };
        bool Is_Driver_Busy(int Driver_ID);
        
        
        //Getters
        int GetDriver_ID()
        {
            return driver_id;
        };
        int GetRide_ID()
        {
            return ride_id;
        };
        string GetPickup_Location()
        {
            return pickup_location;
        };
        string GetDropoff_Location()
        {
            return dropoff_location;
        };
        time_t GetPickup_Time()
        {
            return pickup_time;
        };
        time_t GetDropoff_Time()
        {
            return dropoff_time;
        };
        int GetParty_Size()
        {
            return party_size;
        };
        int GetStatus()
        {
            return status;
        };
        int GetRating_By_Customer()
        {
            return rating_by_customer;
        };
        string GetPets()
        {
            return pets;
        };
        vector<int> GetDriver_IDs()
        {
            return driver_ids;
        }

        void Print_Info();

};

#endif