/*
    ====basic.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   4/14/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====basic.h====
*/

#ifndef basic_h
#define basic_h

#include <iostream>
#include <string>
#include "base.h"
using namespace std;

class Basic : public Base
{
    private:
        int cargo_cap;

    public:
        //Constructor
        Basic();
        
        //Destructor
        ~Basic();

        //Setters
        void SetCargo_Cap(int Cargo_Cap)
        {
            cargo_cap = Cargo_Cap;
        };
        //Getters
        int GetCargo_Cap()
        {
            return cargo_cap;
        };
        
        int Get_Type()
        {
            return BASIC;
        };
        

        void Print_Info();
        void Edit_Info();
    
};

#endif