/*
    ====base.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   4/14/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====base.h====
*/

#ifndef base_h
#define base_h

#define ECONOMY 1
#define BASIC 2
#define GROUP 3
#define LUXURY 4

#include <iostream>
using namespace std;

class Base
{
    private:
        int no_passengers;
        int no_baggage;
        int id;

    public:
    
        //Destructor
        virtual ~Base();

        //Setters
        void SetNo_Passengers(int No_Passengers)
        {
            no_passengers = No_Passengers;
        };
        void SetNo_Baggage(int No_Baggage)
        {
            no_baggage = No_Baggage;
        };
        void SetID(int ID)
        {
            id = ID;
        };

        //Getters
        int GetNo_Passengers()
        {
            return no_passengers;
        };
        int GetNo_Baggage()
        {
            return no_baggage;
        };
        int GetID()
        {
            return id;
        };

        virtual int Get_Type() = 0; //returns the type (Economy, Basic, Group, Luxury)
        virtual void Print_Info();
        virtual void Edit_Info();

       

};

#endif