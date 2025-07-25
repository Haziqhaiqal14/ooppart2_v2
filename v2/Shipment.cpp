#include <string>

using namespace std;

#include "Shipment.h"

Shipment::Shipment() : id(""), place(""), time("") {}

Shipment::Shipment(string id, string place, string time) : id(id), place(place), time(time) {}

void Shipment::setId(string id) { this->id = id; }
void Shipment::setPlace(string place) { this->place = place; }
void Shipment::setTime(string time) { this->time = time; }

string Shipment::getId() const { return id; }
string Shipment::getPlace() const { return place; }
string Shipment::getTime() const { return time; }
