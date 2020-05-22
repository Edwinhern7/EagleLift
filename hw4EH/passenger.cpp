/*
    ====passenger.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====passenger.cpp====
*/
#include <iostream>
#include <string>
#include <iomanip> // for  std::setprecision(value);
#include "passenger.h"
using namespace std;

void Passenger::Print_Info()
{
    cout << "\t" << passenger_name << "\t\t" << passenger_id << "\t\t" << payment_preference << "\t\t" << handicapped << "\t\t" << pets << "\t\t" << handicapped << endl;

}

