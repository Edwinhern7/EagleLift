/*
    ====base.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   4/14/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====base.cpp====
*/

#include <iostream>
#include "base.h"
#include <iterator>
#include <vector>
using namespace std;


Base::~Base()
{

}

void Base::Edit_Info()
{

}


//Print Info
void Base::Print_Info()
{
    cout << "Number of passengers: " << no_passengers << endl;
    cout << "Number of luggage: " << no_baggage << endl;
}