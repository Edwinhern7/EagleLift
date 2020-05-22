/*
    ====drivers.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   3/11/20
EMAIL:          Edwinhernandez2@my.unt.edu
COURSE:         CSCE 1040
Copyright (c) 2020 Edwin Hernandez
    ====drivers.cpp====
*/

#include <iostream>
#include <iterator>
#include <iomanip>
#include <string>
#include <fstream>

#include "drivers.h"
#include "driver.h"

#include "economy.h"
#include "basic.h"
#include "group.h"
#include "luxury.h"
using namespace std;

void Drivers::Driver_Info()
{
    Driver New_Driver;
    Base *NewDriver = nullptr;
    bool valid_Type = false;
    int driver_id; // (6 digits)
    string pets; //Boolean asking if driver allows pets 
    string handicapped; //Boolean asking if handicapped capable
    string driver_name;
    string type;
    int id; //4 digit value

    //Enter Driver Type
    cout << "_____DRIVER_TYPES_____\n";
    cout << "1. Economy\n";
    cout << "2. Basic\n";
    cout << "3. Group\n";
    cout << "4. Luxury\n";
    cout << "Enter the driver type that is associated with your type: ";
    cin >> type;
    cin.ignore();
    //Driver Name
    cout << "Enter Driver Name: ";
    getline(cin,driver_name);
    New_Driver.SetDriver_Name(driver_name);

    //Enter Driver ID
    cout << "Enter Driver ID (6 digit value): ";
    cin >> driver_id;
    cin.ignore();
    while(to_string(driver_id).length() != 6)
    {
        cout << "Please enter a 6 value Driver ID ";
        cin >> driver_id;
        cin.ignore();
    }
    while(Drivers::Is_ID_Taken(driver_id))
    {
        cout << "Driver ID is already taken. Please input another: ";
        cin >> driver_id;
    }
    New_Driver.SetDriver_ID(driver_id);
    //Enter a backup id
    
    cout << "Enter a backup ID (4 digit value): ";
    cin >> id;
    cin.ignore();
    while(to_string(id).length() != 4)
    {
        cout << "Please enter a 4 digit value: ";
        cin >> id;
        cin.ignore();
    }
    while(Drivers::Is_Backup_ID_Taken(id))
    {
        cout << "Backup ID is already taken. Please input another: ";
        cin >> id;
        cin.ignore();
    }
   
    //Specific to driver type 
    do{
        //Info for Economy
        if( type[0] == 'E' || type[0] == 'e')
        {
            NewDriver = new Economy();
            valid_Type = true;

            //Economy Data
            int no_passengers;
            int no_baggage;
            Economy* newEconomy = dynamic_cast<Economy*>(NewDriver);
            //Enter passenger amount
            cout << "Enter number of passengers allowed (0-2): ";
            cin >> no_passengers;
            cin.ignore();
            while(no_passengers > 2 || no_passengers < 0)
            {
                cout << "Please enter a valid number from (0-2): ";
                cin >> no_passengers;
                cin.ignore();
            }
            newEconomy->SetNo_Passengers(no_passengers);
            //Enter baggage amount
            cout << "Enter number of baggage allowed (0-2): ";
            cin >> no_baggage;
            cin.ignore();
            while(no_baggage > 2 || no_baggage < 0)
            {
                cout << "Please enter a valid number from (0-2): ";
                cin >> no_baggage;
                cin.ignore();
            }
            newEconomy->SetNo_Baggage(no_baggage);
        }
        //Info for Basic
        else if((type[0] == 'B' || type[0] == 'b') && (type[1] == 'A' || type[1] == 'a'))
        {
            NewDriver = new Basic();
            valid_Type = true;
            int no_passengers;
            int no_baggage;
            int cargo_cap;
            Basic* newBasic = dynamic_cast<Basic*>(NewDriver);
            //Enter passenger amount
            cout << "Enter number of passengers allowd (2-4): ";
            cin >> no_passengers;
            cin.ignore();
            while(no_passengers > 4 || no_passengers < 2)
            {
                cout << "Please enter a valid number from (2-4): ";
                cin >> no_passengers;
                cin.ignore();
            }
            newBasic->SetNo_Passengers(no_passengers);
            //Enter baggage amount
            cout << "Enter number of baggage allowed (2-3): ";
            cin >> no_baggage;
            cin.ignore();
            while(no_baggage > 3 || no_baggage < 2)
            {
                cout << "Please enter a valid number from (2-3): ";
                cin >> no_baggage;
                cin.ignore();
            }
            newBasic->SetNo_Baggage(no_baggage);
            //Enter cargo amount
            cout << "Enter number of cargo allowed (0-1): ";
            cin >> cargo_cap;
            cin.ignore();
            while(cargo_cap > 1 || cargo_cap < 0)
            {
                cout << "Please enter a valid number from (0-1): ";
                cin >> cargo_cap;
                cin.ignore();
            }
            newBasic->SetCargo_Cap(cargo_cap);
        }
        //Info for Group
        else if((type[0] == 'G' || type[0] == 'g') && (type[1] == 'R' || type[1] == 'r'))
        {
            NewDriver = new Group();
            valid_Type = true;
            int no_passengers;
            int no_baggage;
            Group* newGroup = dynamic_cast<Group*>(NewDriver);
            //Enter type of group
            newGroup->SetGroupType();
            //Enter passengers allowed
            cout << "Enter number of passengers allowed (5-7): ";
            cin >> no_passengers;
            cin.ignore();
            while(no_passengers > 7 || no_passengers < 5)
            {
                cout << "Please enter a valid number (5-7): ";
                cin >> no_passengers;
                cin.ignore();
            }
            newGroup->SetNo_Passengers(no_passengers);
            //Enter baggage allowed
            cout << "Enter number of baggage allowed (4-6): ";
            cin >> no_baggage;
            cin.ignore();
            while(no_baggage > 6 || no_baggage < 4)
            {
                cout << "Please enter a valid number (4-6): ";
                cin >> no_baggage;
                cin.ignore();
            }
            newGroup->SetNo_Baggage(no_baggage);
        }
        //Info for Luxury
        else if((type[0] == 'L' || type[0] == 'l') && (type[1] == 'U' || type[1] == 'u'))
        {
            NewDriver = new Luxury();
            valid_Type = true;
            int no_passengers;
            Luxury* newLuxury = dynamic_cast<Luxury*>(NewDriver);
            //Enter luxury group
            newLuxury->SetLuxuryType();
            //Enter passenger allowed
            cout << "Enter number of passengers allowed (1-2): ";
            cin >> no_passengers;
            cin.ignore();
            while(no_passengers > 2 || no_passengers < 1)
            {
                cout << "Please enter a valid number (1-2): ";
                cin >> no_passengers;
                cin.ignore();
            }
            newLuxury->SetNo_Passengers(no_passengers);
        }
        else
        {
            cout << "Invalid Driver Type. Enter a Driver Type: ";
            cin >> type;
            cin.ignore();
        }
    }while(!valid_Type);
    
    //Enter if pets are allowed
    cout << "Allow Pets? ( Yes |  No ): ";
    cin.ignore();
    getline(cin, pets);
    New_Driver.SetPets(pets);

    //Enter if handicapped
    cout << "Allow Handicapped? ( Yes | No ): ";
    getline(cin,handicapped);
    New_Driver.SetHandicapped(handicapped);

    NewDriver->SetID(id);

    Drivers.push_back(New_Driver);
    Bases.push_back(NewDriver);
}

void Drivers::Modify_Driver() 
{
    int driver_id;
    int backup_id;
    cout << "Enter Driver ID: ";
    cin >> driver_id;
    cin.ignore();

    cout << "Enter backup ID: ";
    cin >> backup_id;
    cin.ignore();
    Base* FindDriverType = FindDriverType_By_ID(backup_id);
    Driver* Driver_With_ID =  FindDriverByID(driver_id);
    if(Driver_With_ID && FindDriverType)
    {
        int choice = -1;
        while(choice != 0)
        {
            cout << "===EDIT DRIVER===\n";
            cout << "0. Exit\n";
            cout << "1. Driver Name\n";
            cout << "2. Driver Type\n";
            cout << "3. Pet Authorization\n";
            cout << "4. Handicap Authorization\n";
            cout << "Enter the number of description you would like to change: ";
            cin >> choice;
            cin.ignore();
            switch(choice)
            {
                case 0:
                    break;
                case 1: 
                {
                    string New_Name;
                    cout << "Enter Driver Name: ";
                    getline(cin, New_Name);
                    Driver_With_ID->SetDriver_Name(New_Name);
                    cout << "Driver Name Changed!\n";
                    break;
                }
                case 2:
                {
                    FindDriverType->Edit_Info();
                    //Add Driver Type and allow the uset to edit their driver type based off what they chose when they added as a new driver
                }
                case 3:
                {
                    string New_Pet;
                    cout << "Allow Pets? ( Yes |  No ): ";
                    getline(cin, New_Pet);
                    Driver_With_ID->SetPets(New_Pet);
                    cout << "Authorization of Pets Changed!\n";
                    break;
                }
                case 4:
                {
                    string New_Handicap;
                    cout << "Allow Handicapped? ( Yes | No ): ";
                    getline(cin, New_Handicap);
                    Driver_With_ID->SetHandicapped(New_Handicap);
                    cout << "Authorization of Handicapped Changed!\n";
                    break;
                }
                default:
                    cout << "Invaild Input. Please enter the number of the option.\n";
                    break;
            }
        }
    }
    else
    {
        cout << "The Driver with that ID is not found. Exiting...\n";
    }
}

void Drivers::Delete_Driver() 
{
    int Driver_ID;
    int backup_id;
    bool RemovedDriver = false;
    bool RemovedDriverType = false;
    vector<Driver>::iterator ptr;
    vector<Base*>::iterator ptr2;
    cout << "Enter Driver ID: ";
    cin >> Driver_ID;
    cin.ignore();
    cout << "Enter backup ID: ";
    cin >> backup_id;
    cin.ignore();

    for(ptr = Drivers.begin(); ptr < Drivers.end(); ptr++)
    {
        if(ptr->GetDriver_ID() == Driver_ID)
        {
            Drivers.erase(ptr);
            cout << "Driver Removed!\n";
            RemovedDriver = true;
        }
    }
    if(!RemovedDriver)
    {
        cout << "Unable to find Driver...\n";
    }
    for(ptr2 = Bases.begin(); ptr2 < Bases.end(); ptr2++)
    {
        if((*ptr2)->GetID() == backup_id)
        {
            delete(*ptr2);
            Bases.erase(ptr2);
            cout << "Driver Type Info Removed!\n";
            RemovedDriverType = true;
        }
        if(!RemovedDriverType)
        {
            cout << "DriverType cannot be found with backup ID. Exiting...\n";
        }
    }
}


void Drivers::Print_All_Drivers()
{
    cout << "===PRINTING ALL DRIVERS===\n";
    cout << "\tDRIVER NAME\t\tDRIVER ID\t\tVEHICLE TYPE\t\tSEATS\t\tPETS\t\tHANDICAPPED\t\tDRIVER RATING\n"; 
    vector<Driver>::iterator ptr;
    vector<Base*>::iterator ptr2;
   
    for(ptr = Drivers.begin(); ptr < Drivers.end(); ptr++)
    {
        ptr->Print_Info();
    } 
    for(ptr2 = Bases.begin(); ptr2 < Bases.end(); ptr2++)
    {
        (*ptr2)->Print_Info();
    }
    
}//Prints the Info of all the Drivers 

void Drivers::Search_Driver()
{
    string Driver_Name;
    cout << "Enter The Name of Driver: ";
    getline(cin, Driver_Name);
    Search_Driver(Driver_Name);
}
void Drivers::Search_Driver(string Driver_Name)
{
    Driver* Driver_With_Name = FindDriverByName(Driver_Name);
    if(Driver_With_Name)
    {
        cout << "\tDRIVER NAME\t\tDRIVER ID\t\tVEHICLE TYPE\t\tSEATS\t\tPETS\t\tHANDICAPPED\t\tDRIVER RATING\n"; 
        Driver_With_Name->Print_Info();
    }
    else
    {
        cout << "Driver Name is not found.\n";
    }        
}

void Drivers::Print_Single_Driver_Info() 
{
    int Driver_ID;
    cout << "Enter Driver ID: ";
    cin >> Driver_ID;
    Print_Single_Driver_Info(Driver_ID);
}

void Drivers::Print_Single_Driver_Info(int Driver_ID)
{
     Driver* Driver_With_ID =  FindDriverByID(Driver_ID);
     if(Driver_With_ID)
     {
         cout << "\tDRIVER NAME\t\tDRIVER ID\t\tVEHICLE TYPE\t\tSEATS\t\tPETS\t\tHANDICAPPED\t\tDRIVER RATING\n"; 
         Driver_With_ID->Print_Info();
     }
     else
     {
         cout << "Driver ID is invalid or can't be found.\n";
     }
} 

bool Drivers::Does_Driver_Have_Enough_Seats(int Driver_ID, int Num_Seats)
{
    vector<Base*>::iterator ptr;
    for(ptr = Bases.begin(); ptr < Bases.end(); ptr++)
    {
        if((*ptr)->GetID() == Driver_ID)
        {
            if((*ptr)->GetNo_Passengers() >= Num_Seats)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
    }
    return false;
}//Searches if the Drivers seats are full or enough

void Drivers::Load_Data()
{
    Bases.clear();
    Drivers.clear();
    ifstream input;
    int All;
    int Driver_Type;
    input.open("drivers.dat");
    input >> All;
    input.ignore();
    for(int n = 0; n < All; n++)
    {
        Driver New_Driver;
        int driver_id; // (6 digits)
        string pets; //Boolean asking if driver allows pets 
        string handicapped; //Boolean asking if handicapped capable
        int driver_rating; //Rate from 0-5
        int numseats; // 
        string vehicle_type; // Compact 2dr, Sedan 4dr, SUV, VAN, other
        string driver_name;
        input >> driver_id;
        cin.ignore();
        input >> driver_rating;
        cin.ignore();
        getline(input, driver_name);
        getline(input, pets);
        getline(input, handicapped);
        getline(input, vehicle_type);

        New_Driver.SetDriver_ID(driver_id);
        New_Driver.SetDriver_Rating(driver_rating);
        New_Driver.SetDriver_Name(driver_name);
        New_Driver.SetPets(pets);
        New_Driver.SetHandicapped(handicapped);

        Drivers.push_back(New_Driver);
    }
    for(int i =0; i < Driver_Type; i++)
    {
        int DriverType;
        input >> DriverType;
        input.ignore();
        //Economy
        if(DriverType == ECONOMY)
        {
            Economy* NewEconomy = new Economy();
            int no_passengers;
            int no_baggage;
            int id;

            input >> no_passengers;
            input.ignore();
            input >> no_baggage;
            input.ignore();
            input >> id;
            input.ignore();
            
            NewEconomy->SetNo_Passengers(no_passengers);
            NewEconomy->SetNo_Baggage(no_baggage);
            NewEconomy->SetID(id);
            Bases.push_back(NewEconomy);
        }
        //Basic
        else if(DriverType == BASIC)
        {
            Basic* NewBasic = new Basic();
            int no_passengers;
            int no_baggage;
            int cargo_cap;
            int id;

            input >> no_passengers;
            input.ignore();
            input >> no_baggage;
            input.ignore();
            input >> id;
            input.ignore();
            input >> cargo_cap;
            input.ignore();
            
            NewBasic->SetNo_Passengers(no_passengers);
            NewBasic->SetNo_Baggage(no_baggage);
            NewBasic->SetID(id);
            NewBasic->SetCargo_Cap(cargo_cap);
            Bases.push_back(NewBasic);
        }
        //Group
        else if(DriverType == GROUP)
        {
            Group* NewGroup = new Group();
            int no_passengers;
            int no_baggage;
            int id;
            int grouptype;

            input >> no_passengers;
            input.ignore();
            input >> no_baggage;
            input.ignore();
            input >> id;
            input.ignore();
            input >> grouptype;
            input.ignore();
            
            NewGroup->SetNo_Passengers(no_passengers);
            NewGroup->SetNo_Baggage(no_baggage);
            NewGroup->SetID(id);
            NewGroup->SetGroupType(static_cast<Group_Type>(grouptype));
            Bases.push_back(NewGroup);
        }
        //Luxury
        else if(DriverType == LUXURY)
        {
            Luxury* NewLuxury = new Luxury();
            int no_passengers;
            int luxuryType;
            int id;

            input >> no_passengers;
            input.ignore();
            input >> luxuryType;
            input.ignore();
            input >> id;
            input.ignore();

            NewLuxury->SetNo_Passengers(no_passengers);
            NewLuxury->SetID(id);
            NewLuxury->SetLuxuryType(static_cast<Luxury_Type>(luxuryType));
            Bases.push_back(NewLuxury);
        }
    }
    input.close();
}//Loads data from dat.

void Drivers::Save_Data()
{
    ofstream output;
    output.open("drivers.dat");
    vector<Driver>::iterator ptr;
    vector<Base*>::iterator ptr2;
    output << Drivers.size() << endl;
    for(ptr = Drivers.begin(); ptr < Drivers.end(); ptr++)
    {
        output << "\t" << ptr->GetDriver_Name() << "\t\t" << ptr->GetDriver_ID() << "\t\t" <<  "\t\t" << ptr->GetVehicle_Type() << "\t\t" << ptr->GetNum_Seats() << "\t\t" << ptr->GetPets() << "\t\t" << ptr->GetHandicapped() << "\t\t" << ptr->GetDriver_Rating() << endl;
    }
    for(ptr2 = Bases.begin(); ptr2 < Bases.end(); ptr2++)
    {
        output << (*ptr2)->Get_Type() << endl;
        output << (*ptr2)->GetID() << endl;
        output << (*ptr2)->GetNo_Passengers() << endl;
        if((*ptr2)->Get_Type() == ECONOMY)
        {
            Economy* economy = dynamic_cast<Economy*>(*ptr2);
            output << economy->GetNo_Baggage() << endl;
        }
        else if((*ptr2)->Get_Type() == BASIC)
        {
            Basic* basic = dynamic_cast<Basic*>(*ptr2);
            output << basic->GetNo_Baggage() << endl;
            output << basic->GetCargo_Cap() << endl;
        }
        else if((*ptr2)->Get_Type() == GROUP)
        {
            Group* group = dynamic_cast<Group*>(*ptr2);
            output << group->GetNo_Baggage() << endl;
            output << group->GetGroupType() << endl;
        }
        else if((*ptr2)->Get_Type() == LUXURY)
        {
            Luxury* luxury = dynamic_cast<Luxury*>(*ptr2);
            output << luxury->GetLuxuryType() << endl;
        }
    }
    output.close();
}//Saves the data of each driver into a data file

void Drivers::Print_All_Rides_Driver()
{

}//Should Print all the rides given by the Driver

Driver* Drivers::FindDriverByID(int Driver_ID)
{
    vector<Driver>::iterator ptr;
    for (ptr = Drivers.begin(); ptr < Drivers.end(); ptr++)
    {
        if(ptr->GetDriver_ID() == Driver_ID)
        {
            return &(*ptr);
        }
    }
    return nullptr;
}//Returns all Drivers with given DriverID



Driver* Drivers::FindDriverByName(string Driver_Name)
{
    vector<Driver>::iterator ptr;
    for(ptr = Drivers.begin(); ptr < Drivers.end(); ptr++)
    {
        if(ptr->GetDriver_Name() == Driver_Name)
        {
            return &(*ptr);
        }
    }
    return nullptr;
}// Returns all Driver with given Driver Name

bool Drivers::Is_ID_Taken(int Driver_ID)
{
    vector<Driver>::iterator ptr;
    for(ptr = Drivers.begin(); ptr < Drivers.end(); ptr++)
    {
        if(ptr->GetDriver_ID() == Driver_ID)
        {
            return true;
        }
    }
    return false;
}

Base* Drivers::FindDriverType_By_ID(int ID)
{
    vector<Base*>::iterator ptr;
    for(ptr = Bases.begin(); ptr < Bases.end(); ptr++)
    {
        if((*ptr)->GetID() == ID)
        {
            return (*ptr);
        }
    }
    cout << "Driver can not be found with given ID.\n";
    return nullptr;
}//Searches for DriverType ID 

string Drivers::CheckDriver_Type(int ID)
{
    return "";
}//Returns something for driver type in the collection

bool Drivers::Is_Backup_ID_Taken(int ID)
{
    vector<Base*>::iterator ptr;
    for(ptr = Bases.begin(); ptr < Bases.end(); ptr++)
    {
        if((*ptr)->GetID() == ID)
        {
            return true;
        }

    }
    return false;
}//Checks if Backup ID is taken from any other Drivers

bool Drivers::Is_DriverType_A_Type(int ID, int DriverType)
{
    Base* DriverWithID = FindDriverType_By_ID(ID);
    if(DriverWithID->Get_Type() == DriverType)
    {
        return true;
    }
    else
    {
        return false;
    }
}//Return whether the DriverType is the correct type 

/*
Drivers::~Drivers()
{
    vector<Base*>::iterator ptr;
    for(ptr = Bases.begin(); ptr < Bases.end(); ptr++)
    {
        delete(*ptr);
    }
}
*/

