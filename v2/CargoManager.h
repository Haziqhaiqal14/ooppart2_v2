#pragma once
#include "BaseShipmentManager.h"
#include "Cargo.h"

class CargoManager : public BaseShipmentManager<Cargo> {
private:
    string formatId(int idNum) const override {
        if (idNum < 10) return "C0" + to_string(idNum);
        return "C" + to_string(idNum);
    }

    string getTypeName() const override {
        return "Cargo";
    }

public:
    CargoManager(string filename) : BaseShipmentManager<Cargo>(filename) {}

    // The addItem, editItem, and deleteItem functions are now inherited from BaseShipmentManager
    // No need to redefine them here
};