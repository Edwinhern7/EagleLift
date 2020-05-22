/*
    ====driver.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====driver.h====
*/

#ifndef driver_h
#define driver_h
#include <iostream>
#include <string>
using namespace std;

class Driver
{
        //attributes
        private:
                int driver_id; // (6 digits)
                string pets; //Boolean asking if driver allows pets 
                string handicapped; //Boolean asking if handicapped capable
                int driver_rating; //Rate from 0-5
                int numseats; // 
                string vehicle_type; // Compact 2dr, Sedan 4dr, SUV, VAN, other
                string driver_name; //20 Characters for first and last name
                
        public:
                //Setters 
             
                void SetDriver_ID(int Driver_ID)
                {
                    driver_id = Driver_ID;
                };
                void SetPets(string Pets)
                {
                    pets = Pets;
                };
                void SetHandicapped(string Handicapped)
                {
                    handicapped = Handicapped;
                };
                void SetDriver_Rating(int Driver_Rating)
                {
                    driver_rating = Driver_Rating;
                };
                void SetVehicle_Type(string Vehicle_Type)
                {
                    vehicle_type = Vehicle_Type;
                };
                void SetDriver_Name(string Driver_Name)
                {
                    driver_name = Driver_Name;
                };
                void SetNum_Seats(int NumSeats)
                {
                    numseats = NumSeats;
                };

                //Getters
                int GetDriver_ID()
                {
                    return driver_id;
                };
                string GetPets()
                {
                    return pets;
                };
                string GetHandicapped()
                {
                    return handicapped;
                };
                int GetDriver_Rating()
                {
                    return driver_rating;
                };
                int GetNum_Seats()
                {
                    return numseats;
                };
                string GetVehicle_Type()
                {
                    return vehicle_type;
                };
                string GetDriver_Name()
                {
                    return driver_name;
                };

                void Print_Info(); //Print all info entered

                

};

#endif
