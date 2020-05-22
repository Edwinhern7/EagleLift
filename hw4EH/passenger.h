/*
    ====passenger.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====passenger.h====
*/
#ifndef passenger_h
#define passenger_h
#include <iostream>
#include <string>
using namespace std;

class Passenger
{
    private:
        string passenger_name;
        int passenger_id;
        string payment_preference;
        string handicapped;
        string pets;
        int default_rating;
    public:
    //Setters
    void SetPassenger_Name(string Passenger_Name)
    {
        passenger_name = Passenger_Name;
    };
    void SetPassenger_ID(int Passenger_ID)
    {
        passenger_id = Passenger_ID;
    };
    void SetPayment_Preference(string Payment_Preference)
    {
        payment_preference = Payment_Preference;
    };
    void SetHandicapped(string Handicapped)
    {
        handicapped = Handicapped;
    };
    void SetPets(string Pets)
    {
        pets = Pets;
    };
    void SetDefault_Rating(int Default_Rating)
    {
        default_rating = Default_Rating;
    };

    string GetPassenger_Name()
    {
        return passenger_name;
    };
    int GetPassenger_ID()
    {
        return passenger_id;
    };
    string GetPayment_Preference()
    {
        return payment_preference;
    };
    string GetHandicapped()
    {
        return handicapped;
    };
    string GetPets()
    {
        return pets;
    };
    int GetDefault_Rating()
    {
        return default_rating;
    };
    
    void Print_Info(); 
};

#endif