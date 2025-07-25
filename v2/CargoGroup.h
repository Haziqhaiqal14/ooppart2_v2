// CargoGroup.h
#pragma once
#include <vector>
#include <memory>
#include "Cargo.h"

class CargoGroup {
private:
    int groupId;
    std::vector<std::shared_ptr<Cargo>> cargos;
    std::string destination;
    std::string latestArrivalTime;

public:
    CargoGroup(int id);

    // Group management
    bool addCargo(const std::shared_ptr<Cargo>& cargo);
    bool removeCargo(const std::string& cargoId);
    bool canAddCargo(const std::shared_ptr<Cargo>& cargo) const;

    // Getters
    int getId() const;
    const std::vector<std::shared_ptr<Cargo>>& getCargos() const;
    std::string getDestination() const;
    std::string getLatestArrivalTime() const;
    size_t size() const;

    // Status
    bool isFull() const;
};