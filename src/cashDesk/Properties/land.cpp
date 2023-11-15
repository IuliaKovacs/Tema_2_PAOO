
#include <iostream>
#include <cstring>
#include "land.h"

land::land(int rank, string street, int number, int surface) : property(street, number, surface)
{
    // cout << "Land constructor in use" << endl;
    this->rank = rank;
}

land::~land()
{
    // cout << "Land destructor in use" << endl;
}

land::land(land &&source) : land(source.rank, source.getStreet(), source.getNumber(), source.getSurface())
{
    cout << "Land move constructor in use" << endl;
    // Steal the data and then null out the source
    source.rank = 0;
    source.setStreet("");
    source.setNumber(0);
    source.setSurface(0);
}

int land::computePayment()
{
    if (getSurface() != 0 && rank != 0)
    {
        return (getSurface() * 10) / rank;
    }
    else
    {
        return 0;
    }
}

void land::show()
{
    cout << "Street: " << getStreet() << endl;
    cout << "Number: " << getNumber() << endl;
    cout << "Surface: " << getSurface() << endl;
    cout << "Rank: " << getRank() << endl;
}
