/*
    ====passengers.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====passengers.h====
*/

#ifndef passengers_h
#define passengers_h

#include <iostream>
#include <string>
#include <vector>
#include "passenger.h"
using namespace std;

class Passengers
{
    private:
        vector<Passenger>Passengers;
    public:
        void Passenger_Info(); //Ask user to add their name, create an ID, handicapped?, pets?, payment preference
        void Modify_Passenger();
        void Delete_Passenger();
        void Print_All_Passengers();
        void Print_Single_Driver_Info();
        void Print_Single_Driver_Info(int Passenger_ID);
        bool Is_ID_Taken(int Passenger_ID);
        void Load_Data();
        void Save_Data();
        void Print_All_Rides_Passengers();
        void Search_Passenger();
        void Search_Passenger(string Passenger_Name);
        Passenger* FindPassengerByID(int Passenger_ID);
        Passenger* FindPassengerByName(string Passenger_Name);

};

#endif
