

#pragma once

#include <cstring>
#include <iostream>
#include "property.h"
using namespace std;

class land : public property
{
    int rank;

public:
    land(int rank, string street, int number, int surface); // Contructor
    ~land();                                                // Destructor
    land(land &&source);                                    // Move Constructor
    void setRank(int rank) { this->rank = rank; }
    int getRank() { return rank; }
    int computePayment();
    void show();
};
