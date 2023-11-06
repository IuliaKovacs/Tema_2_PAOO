
#pragma once

#include <cstring>
#include <iostream>
using namespace std;

namespace cashDesk
{

    class property
    {
        string street;
        int number;
        int surface;
    public:
        property(string street, int number, int surface);
        ~property();
        void setStreet(string street) { this->street = street; }
        void setNumber(int number){ this->number = number; }
        void setSurface(int surface){ this->surface = surface; }
        string getStreet(){ return street; }
        int getNumber(){ return number; }
        int getSurface() { return surface; }
        virtual int computePayment() = 0; //pure virtual function
        virtual void show() = 0; //pure virtual function
    };

    class building : public property
    {   
        int apartmentNumber;
    public:
        building(int apartmentNumber, string street, int number, int surface);
        ~building();
        void setApartmentNumber(int apartmentNumber){ this->apartmentNumber = apartmentNumber; }
        int getApartmentNumber(){ return apartmentNumber; }
        int computePayment();
        void show();
    };

    class land : public property
    {   int rank;
    public:
        land(int rank, string street, int number, int surface);
        ~land();
        void setRank(int rank){ this->rank = rank; }
        int getRank(){ return rank; }
        int computePayment();
        void show();
    };

    class contributor
    {
        property *properties[4];
        int propertiesNumber;
    public:
        contributor();
        ~contributor();
        int getPropertiesNumber() { return propertiesNumber; }
        void addProperty(property *property);
        int computeTotalPayment();
    };
    
}


