
#include <iostream>
#include <cstring>
#include "cashDesk.h"

namespace cashDesk
{

    property::property(string street, int number, int surface)
    {
        cout<<"Property constructor in use"<<endl;
        this->street = street;
        this->number = number;
        this->surface = surface;
    }

    property::~property()
    {
        cout<<"Property destructor in use"<<endl;
    }

    building::building(building &&source) : building(source.apartmentNumber, source.getStreet(), source.getNumber(), source.getSurface())
    {
        cout<<"Building move constructor in use"<<endl;
        // Steal the data and then null out the source 
        source.apartmentNumber = 0;
        source.setStreet("");
        source.setNumber(0);
        source.setSurface(0);
    }

    building::building(int apartmentNumber, string street, int number, int surface) : property(street, number, surface)
    {
        cout<<"Building constructor in use"<<endl;
        this->apartmentNumber = apartmentNumber;
    }

    building::~building()
    {
        cout<<"Building destructor in use"<<endl;
    }
    
    int building::computePayment()
    {   
        if (getSurface() != 0 )
        {
            return getSurface()*10;  
        }
        else 
        {
            return 0;
        }
    }

    void building::show()
    {
        cout<<"Street: "<<getStreet()<<endl;
        cout<<"Number: "<<getNumber()<<endl;
        cout<<"Surface: "<<getSurface()<<endl;
        cout<<"Apartment: "<<getApartmentNumber()<<endl;
    }

    land::land(int rank, string street, int number, int surface) : property(street, number, surface)
    {
        cout<<"Land constructor in use"<<endl;
        this->rank = rank;
    }

    land::~land()
    {
        cout<<"Land destructor in use"<<endl;
    }

    land::land(land &&source) : land(source.rank, source.getStreet(), source.getNumber(), source.getSurface())
    {   
        cout<<"Land move constructor in use"<<endl;
        // Steal the data and then null out the source 
        source.rank = 0;
        source.setStreet("");
        source.setNumber(0);
        source.setSurface(0);
    }

    int land::computePayment()
    {
        if(getSurface() != 0 && rank != 0)
        {
            return (getSurface()*10)/rank;
        }
        else 
        {
            return 0;
        }
    }

    void land::show()
    {
        cout<<"Street: "<<getStreet()<<endl;
        cout<<"Number: "<<getNumber()<<endl;
        cout<<"Surface: "<<getSurface()<<endl;
        cout<<"Rank: "<<getRank()<<endl;
    }

    contributor::contributor()
    {
        cout<<"Contributor constructor in use"<<endl;
        this->propertiesNumber = 0;
    }

    contributor::~contributor()
    {
        cout<<"Contributor destructor in use"<<endl;
    }

    void contributor::addProperty(property *property)
    {
        properties[propertiesNumber] = property;
        propertiesNumber++;
    }

    int contributor::computeTotalPayment()
    {
        int totalPayment = 0;

        for (int i=0; i<propertiesNumber; i++)
        {
            totalPayment += properties[i]->computePayment(); 
        }

        return totalPayment;
    }

}