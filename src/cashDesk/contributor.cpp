
#include <iostream>
#include <cstring>
#include "contributor.h"

contributor::contributor()
{
    // cout << "Contributor constructor in use" << endl;
    this->propertiesNumber = 0;
}

contributor::~contributor()
{
    // cout << "Contributor destructor in use" << endl;
}

void contributor::addProperty(property *property)
{
    properties[propertiesNumber] = property;
    propertiesNumber++;
}

int contributor::computeTotalPayment()
{
    int totalPayment = 0;

    for (int i = 0; i < propertiesNumber; i++)
    {
        totalPayment += properties[i]->computePayment();
    }

    previousTaxes.push_back(totalPayment);

    return totalPayment;
}
