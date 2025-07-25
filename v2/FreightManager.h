#pragma once
#include "BaseShipmentManager.h"
#include "Freight.h"

class FreightManager : public BaseShipmentManager<Freight> {
private:
    string formatId(int idNum) const override {
        if (idNum < 10) return "F0" + to_string(idNum);
        return "F" + to_string(idNum);
    }

    string getTypeName() const override {
        return "Freight";
    }

public:
    FreightManager(string filename) : BaseShipmentManager<Freight>(filename) {}

    // The addItem, editItem, and deleteItem functions are now inherited from BaseShipmentManager
    // No need to redefine them here
};