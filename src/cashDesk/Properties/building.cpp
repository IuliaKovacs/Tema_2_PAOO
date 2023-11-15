#include <iostream>
#include <cstring>
#include "building.h"

building::building(building &&source) : building(source.apartmentNumber, source.getStreet(), source.getNumber(), source.getSurface())
{
    // cout << "Building move constructor in use" << endl;
    // Steal the data and then null out the source
    source.apartmentNumber = 0;
    source.setStreet("");
    source.setNumber(0);
    source.setSurface(0);
}

building::building(int apartmentNumber, string street, int number, int surface) : property(street, number, surface)
{
    // cout << "Building constructor in use" << endl;
    this->apartmentNumber = apartmentNumber;
}

building::~building()
{
    cout << "Building destructor in use" << endl;
}

int building::computePayment()
{
    if (getSurface() != 0)
    {
        return getSurface() * 10;
    }
    else
    {
        return 0;
    }
}

void building::show()
{
    cout << "Street: " << getStreet() << endl;
    cout << "Number: " << getNumber() << endl;
    cout << "Surface: " << getSurface() << endl;
    cout << "Apartment: " << getApartmentNumber() << endl;
}
