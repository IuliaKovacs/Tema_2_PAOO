
#pragma once

#include <cstring>
#include <iostream>
#include "Properties/property.h"
#include <vector>
using namespace std;

class contributor
{
    property *properties[4];
    int propertiesNumber;
    vector<int> previousTaxes;

public:
    contributor();
    ~contributor();
    int getPropertiesNumber() { return propertiesNumber; }
    vector<int> getPreviosTaxes() { return previousTaxes; }
    void addProperty(property *property);
    int computeTotalPayment();
    
};
