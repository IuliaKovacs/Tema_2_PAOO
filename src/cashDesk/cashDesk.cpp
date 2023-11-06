
#include <iostream>
#include <cstring>
#include "cashDesk.h"

namespace cashDesk
{

    property::property(string street, int number, int surface)
    {
        cout<<"Property constructor in use"<<'\n';
        this->street = street;
        this->number = number;
        this->surface = surface;
    }

    property::~property()
    {
        cout<<"Property destructor in use"<<'\n';
    }

    building::building(int apartmentNumber, string street, int number, int surface) : property(street, number, surface)
    {
        cout<<"Building constructor in use"<<'\n';
        this->apartmentNumber = apartmentNumber;
    }

    building::~building()
    {
        cout<<"Building destructor in use"<<'\n';
    }
    
    int building::computePayment()
    {
        return getSurface()*500;    
    }

    void building::show()
    {
        cout<<"Street: "<<getStreet()<<'\n';
        cout<<"Number: "<<getNumber()<<'\n';
        cout<<"Surface: "<<getSurface()<<'\n';
        cout<<"Apartment: "<<getApartmentNumber()<<'\n';
    }

    land::land(int rank, string street, int number, int surface) : property(street, number, surface)
    {
        cout<<"Land constructor in use"<<'\n';
        this->rank = rank;
    }

    land::~land()
    {
        cout<<"Land destructor in use"<<'\n';
    }

    int land::computePayment()
    {
        return (getSurface()*350)/rank;
    }

    void land::show()
    {
        cout<<"Street: "<<getStreet()<<'\n';
        cout<<"Number: "<<getNumber()<<'\n';
        cout<<"Surface: "<<getSurface()<<'\n';
        cout<<"Rank: "<<getRank()<<'\n';
    }

    contributor::contributor()
    {
        cout<<"Contributor constructor in use"<<'\n';
        this->propertiesNumber = 0;
    }

    contributor::~contributor()
    {
        cout<<"Contributor destructor in use"<<'\n';
    }

    void contributor::addProperty(property *property)
    {
        properties[propertiesNumber] = *property;
        propertiesNumber++;
    }

    int contributor::computeTotalPayment()
    {
        int totalPayment = 0;

        for (int i=0; i<propertiesNumber; i++)
        {
            totalPayment += properties[i].computePayment(); 
        }

        return totalPayment;
    }

}