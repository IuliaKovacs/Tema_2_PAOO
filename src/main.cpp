

#include "cashDesk/cashDesk.h"
#include <iostream>

using namespace cashDesk;
using namespace std;

int main() {
    
    building house = building(15, "High Street", 6, 30);
    building house2 = building(7, "Maple Street", 10, 50);
    land verdantValley = land(10, "Oak Street", 100, 1000);

    contributor Mihai = contributor();

    property *p; //creating a pointer to property type 

    p = &house;

    Mihai.addProperty(p);

    p = &house2;

    Mihai.addProperty(p);

    p = &verdantValley;

    Mihai.addProperty(p);

    cout<<"Total number of properties: "<<Mihai.getPropertiesNumber()<<endl;

    int totalPayment =  Mihai.computeTotalPayment();

    cout<<"----- Polymorphism part -----"<<endl;

    cout<<"Total Payment for Mihai: "<<totalPayment<<endl;

    return 0;
}




