/*
    ====group.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   4/14/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====group.h====
*/

#ifndef group_h
#define group_h

#include <iostream>
#include <string>
#include "base.h"
using namespace std;

enum Group_Type : int {Limo = 0, PartyBus};

class Group : public Base
{   
    private:
        Group_Type GroupType;

    public:
        //Constructor
        Group();

        //Destructor
        ~Group();

        //Setters
        void SetGroupType(Group_Type Group_Type);
        void SetGroupType(); //Prompts for user input

        //Getters
        Group_Type GetGroupType()
        {
            return GroupType;
        };
        string GetGroupType_As_String(); //Returns a string that says the GroupType
        
        int Get_Type() //returns with the # code 
        {
            return GROUP;
        };
        
        void Print_Info(); //Prints Info
        void Edit_Info(); //Prompts user to edit info
        

};

#endif