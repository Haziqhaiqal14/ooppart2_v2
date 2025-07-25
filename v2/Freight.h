// Freight.h (extending Shipment)
#pragma once
#include "Shipment.h"
#include "Cargo.h"
#include <vector>
#include <memory>

class Freight : public Shipment {
protected:
    int maxCapacity;
    std::vector<std::shared_ptr<Cargo>> assignedCargos;

public:
    Freight(const std::string& id, const std::string& place, const std::string& time, int capacity);

    // Getters
    int getMaxCapacity() const;
    int getCurrentLoad() const;
    const std::vector<std::shared_ptr<Cargo>>& getAssignedCargos() const;

    // Operations
    virtual bool canAssignCargo(const std::shared_ptr<Cargo>& cargo) const;
    virtual bool assignCargo(const std::shared_ptr<Cargo>& cargo);
    virtual bool removeCargo(const std::string& cargoId);
    virtual bool isFull() const;
    virtual std::string getType() const = 0;

    void display() const override;
};

class MiniMover : public Freight {
public:
    MiniMover(const std::string& id, const std::string& place, const std::string& time);
    std::string getType() const override;
};

class CargoCruiser : public Freight {
public:
    CargoCruiser(const std::string& id, const std::string& place, const std::string& time);
    std::string getType() const override;
};

class MegaCarrier : public Freight {
public:
    MegaCarrier(const std::string& id, const std::string& place, const std::string& time);
    std::string getType() const override;
};