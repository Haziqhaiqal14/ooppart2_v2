#include <iostream>
#include <string>

using namespace std;

#include "Freight.h"

Freight::Freight() : Shipment() {}
Freight::Freight(string id, string place, string time) : Shipment(id, place, time) {}

void Freight::display() const {
    cout << "Freight ID: " << getId() << ", Destination: " << getPlace() << ", Time: " << getTime() << endl;
}
