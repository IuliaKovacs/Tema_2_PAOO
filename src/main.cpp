

#include "cashDesk/cashDesk.h"
#include <iostream>

using namespace cashDesk;
using namespace std;

int main() {
    
    building house = building(15, "High Street", 6, 300);
    building house2 = building(7, "Maple Street", 10, 500);
    land verdantValley = land(3, "Oak Street", 100, 10000);

    contributor Mihai = contributor();

    property *p; //creating a pointer to property type 

    p = &house;

    Mihai.addProperty(p);

    p = &house2;

    Mihai.addProperty(p);

    p = &verdantValley;

    Mihai.addProperty(p);

    int totalPayment =  Mihai.computeTotalPayment();

    cout<<totalPayment;

    return 0;
}




