/*
    ====driver.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====driver.cpp====
*/
#include <iostream>
#include <string>
#include <iomanip> // for  std::setprecision(value);
#include "driver.h"
using namespace std;


void Driver::Print_Info()
 {
         cout << "\t" << driver_name << "\t\t" << driver_id << "\t\t" << vehicle_type << "\t\t\t" << numseats << "\t\t" << pets << "\t\t" << handicapped << "\t\t        " << driver_rating << endl;
 }
