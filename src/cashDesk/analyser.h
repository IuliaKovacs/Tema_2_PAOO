#include <iostream>
#include <vector>
#include <memory>
#include "Properties/property.h"

template <class T>
class analyser
{
    vector<shared_ptr<property>> list;

public:
    //constructor
    explicit analyser(const vector<shared_ptr<property>> &list) : list(list) {}
    
    T computeAverageOfAllTaxes();
    template <class G> T getNoOfTaxesGreaterThen(G value);
};