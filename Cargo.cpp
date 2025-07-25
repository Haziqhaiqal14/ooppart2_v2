#include "Cargo.h"
#include <iostream>

Cargo::Cargo(std::string id, std::string dest, std::string time, int groupId)
    : Shipment(id, dest, time), groupId(groupId) {
}

void Cargo::display() const {
    std::cout << "Cargo ID: " << id
        << ", Destination: " << destination
        << ", Time: " << time
        << ", Group: " << groupId << std::endl;
}