#include <iostream>
#include <string>

using namespace std;

#include "Cargo.h"

Cargo::Cargo() : Shipment() {}
Cargo::Cargo(string id, string place, string time) : Shipment(id, place, time) {}

void Cargo::display() const {
    cout << "Cargo ID: " << getId() << ", Destination: " << getPlace() << ", Time: " << getTime() << endl;
}
