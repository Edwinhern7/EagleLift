/*
    ====economy.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   4/14/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====economy.h====
*/

#ifndef economy_h
#define economy_h

#include <iostream>
#include "base.h"
using namespace std;

class Economy : public Base
{
    private:

    public:
        //Constructor
        Economy();
        Economy(int No_Passengers, int No_Baggage);

        //Destructor
        ~Economy();

        void Print_Info(); //Prints Info
        void Edit_Info(); //Prompts to Edit Economy Info
        
        int Get_Type()
        {
            return ECONOMY;
        };
        

};

#endif
