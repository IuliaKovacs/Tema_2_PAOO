
#pragma once

#include <iostream>
using namespace std;

namespace cashDesk
{

    class property
    {
        char street[20];
        int number;
        int surface;
    public:
        property(char street[], int number, int surface);
        ~property();
        void setStreet(char street[] ) { strcpy(this->street, street); }
        void setNumber(int number){ this->number = number; }
        void setSurface(int surface){ this->surface = surface; }
        char* getStreet(){ return street; }
        int getNumber(){ return number; }
        int getSurface() { return surface; }
        virtual int computePayment() = 0; //pure virtual function
        virtual void show() = 0; //pure virtual function
    };

    class building : public property
    {   
        int apartmentNumber;
    public:
        building(int apartmentNumber, char street[], int number, int surface);
        ~building();
        void setApartmentNumber(int apartmentNumber){ this->apartmentNumber = apartmentNumber; }
        int getApartmentNumber(){ return apartmentNumber; }
        int computePayment();
        void show();
    };

    class land : public property
    {   int rank;
    public:
        land(int rank, char street[], int number, int surface);
        ~land();
        void setRank(int rank){ this->rank = rank; }
        int getRank(){ return rank; }
        int computePayment();
        void show();
    };

    class contributor
    {
        property *properties;
        int propertiesNumber;
    public:
        contributor();
        ~contributor();
        void addProperty(property property);
    };
    
}


