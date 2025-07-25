#pragma once
#include <string>

class Shipment {
private:
    string id;
    string place;
    string time;

public:
    Shipment();
    Shipment(string id, string place, string time);
    virtual ~Shipment() = default;

    // Setters
    void setId(string id);
    void setPlace(string place);
    void setTime(string time);

    // Getters
    string getId() const;
    string getPlace() const;
    string getTime() const;

    virtual void display() const = 0;

};
