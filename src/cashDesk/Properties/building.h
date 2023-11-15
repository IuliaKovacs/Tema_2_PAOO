
#pragma once

#include <cstring>
#include <iostream>
#include "property.h"
using namespace std;

class building : public property
{
    int apartmentNumber;

public:
    building(int apartmentNumber, string street, int number, int surface); // Constructor
    ~building();                                                           // Destructor
    building(building &&source);                                           // Move Constructor
    void setApartmentNumber(int apartmentNumber) { this->apartmentNumber = apartmentNumber; }
    int getApartmentNumber() { return apartmentNumber; }
    int computePayment();
    void show();
};
