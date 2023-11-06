

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

    cout<<"----- Polymorphism part -----"<<endl;

    cout<<"Total number of properties: "<<Mihai.getPropertiesNumber()<<endl;

    cout<<"Total Payment for Mihai: "<<Mihai.computeTotalPayment()<<endl;

    cout<<"----- Move constructor part -----"<<endl;
    cout<<"----- Moving the content from house2 object in newHouse object "<<endl;
    cout<<"----- The compute payment should show less because we cleared house2 fields "<<endl;

    building newHouse = std::move(house2);

    land newLand = std::move(verdantValley);

    cout<<"-----    old land         -----"<<endl;
    verdantValley.show();

    cout<<"----- new created land with move constructor  -----"<<endl;
    newLand.show();

    cout<<"Total Payment for Mihai: "<<Mihai.computeTotalPayment()<<endl;
    cout<<"-----                 -----"<<endl;

    return 0;
}




