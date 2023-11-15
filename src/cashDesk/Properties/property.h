#pragma once

#include <cstring>
#include <iostream>
using namespace std;

class property
{
    string street;
    int number;
    int surface;

public:
    property(string street, int number, int surface); // Constructor
    ~property();                                      // Destructor
    void setStreet(string street) { this->street = street; }
    void setNumber(int number) { this->number = number; }
    void setSurface(int surface) { this->surface = surface; }
    string getStreet() { return street; }
    int getNumber() { return number; }
    int getSurface() { return surface; }
    virtual int computePayment() = 0; // pure virtual function
    virtual void show() = 0;          // pure virtual function
};
