
#include "analyser.h"

template<class T>
T analyser<T>::computeAverageOfAllTaxes()
{
    int no = 0, sum = 0;

    for (auto it = list.begin(); it != list.end(); it++)
    {
        sum += (*it)->computePayment();
        no++;
    }

    return ((T)sum)/((T)no);
} 

template<class T>
template<class G>
T analyser<T>::getNoOfTaxesGreaterThen(G threshold)
{
    int no = 0;

    for (auto it = list.begin(); it != list.end(); it++)
    {
        if ( (*it)->computePayment() > threshold )
        {
            no++;
        }
    }

    return (T)no;
} 
