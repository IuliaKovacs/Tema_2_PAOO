
#include <iostream>
#include <cstring>
#include "property.h"

property::property(string street, int number, int surface)
{
    // cout << "Property constructor in use" << endl;
    this->street = street;
    this->number = number;
    this->surface = surface;
}

property::~property()
{
    // cout << "Property destructor in use" << endl;
}
