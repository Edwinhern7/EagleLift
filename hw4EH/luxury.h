/*
    ====luxury.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   4/14/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====luxury.h====
*/

#ifndef luxury_h
#define luxury_h

#include <iostream>
#include "base.h"
using namespace std;

enum Luxury_Type : int {Mercedes = 0, Tesla, Porsche , GTR};

class Luxury : public Base
{
    private:
        Luxury_Type LuxuryType;

    public:
        //Constructor
        Luxury();

        //Destructor
        ~Luxury();
        
        //Getters
        Luxury_Type GetLuxuryType()
        {
            return LuxuryType;
        };
        
        int Get_Type() //returns with the # code 
        {
            return LUXURY;
        };
        
        string GetLuxuryType_As_String(); // returns a string that says Luxury type

        void SetLuxuryType(Luxury_Type LuxuryType_);
        void SetLuxuryType(); //Prompts for user info

        void Print_Info(); // Prints info
        void Edit_Info();// Edits Info

};

#endif