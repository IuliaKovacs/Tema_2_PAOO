

#include "CashDesk/Properties/property.h"
#include "CashDesk/Properties/land.h"
#include "CashDesk/Properties/building.h"
#include "CashDesk/contributor.h"
#include "CashDesk/analyser.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T, typename U> bool comparePayment( T& a,  U& b)
{
    if (a.computePayment() > b.computePayment())
    {
        return true;
    }
    else 
    {
        return false;
    }
}

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

    cout<<"-----                 -----"<<endl;
    cout<<"-----                 -----"<<endl;
    cout<<"-----                 -----"<<endl;
    cout<<"-----                 -----"<<endl;
    cout<<"-----       Homework 3      -----"<<endl;

    cout<<"----- Move constructor part -----"<<endl;
    // cout<<"----- Moving the content from house2 object in newHouse object "<<endl;
    // cout<<"----- The compute payment should show less because we cleared house2 fields "<<endl;

    auto house3 = make_unique<building>(10, "Oak Street", 100, 40);
    house3->show();
    unique_ptr<building> newHouse = std::move(house3);
    newHouse->show();
    cout<<" -- Memory auto dealocated because of the unique pointer --"<<endl;
    land newLand = std::move(verdantValley);
    // newLand.show();

    // cout<<"-----    old land         -----"<<endl;
    // verdantValley.show();

    // cout<<"----- new created land with move constructor  -----"<<endl;
    // newLand.show();

    cout<<"Total Payment for Mihai: "<<Mihai.computeTotalPayment()<<endl;
   

    cout<<"-- Display the vector used for storing all the taxes: "<<endl;
    vector<int> aux = Mihai.getPreviosTaxes();

    for (auto it = aux.begin(); it != aux.end(); ++it)
    {
        cout<<*it<<endl;
    }

    cout<<"-----                 -----"<<endl;

    bool result = comparePayment<building, land>(house, newLand);

    cout<<"The compare payment result is: "<<result<<endl;

    cout<<"-----                 -----"<<endl;

    cout<<"-----  Template class part      -----"<<endl;

    vector<shared_ptr<property>> list = {
        make_shared<building>(7, "Street no 1", 1, 70),
        make_shared<building>(8, "Street no 2", 2, 80),
        make_shared<land>(100, "Street no 1", 1, 1000)
    };

    analyser<int> analyserAux(list);

    cout<<"Average of taxes: "<<analyserAux.computeAverageOfAllTaxes()<<endl;

    return 0;
}




