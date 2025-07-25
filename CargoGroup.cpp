/*****************************************************************************
 * Author:    Haziq Haiqal
 * File:      CargoGroup.cpp
 * Purpose:   Implementation of CargoGroup.
 *****************************************************************************/
#include "CargoGroup.h"

CargoGroup::CargoGroup(int id)
    : groupId_(id), destination_(), latestArrivalTime_("00:00") {
}

bool CargoGroup::canAddCargo(const std::shared_ptr<Cargo>& cargo) const {
    return cargos_.size() < 10
        && (destination_.empty() || cargo->getDestination() == destination_);
}

bool CargoGroup::addCargo(const std::shared_ptr<Cargo>& cargo) {
    if (!canAddCargo(cargo)) return false;
    if (destination_.empty()) destination_ = cargo->getDestination();
    cargos_.push_back(cargo);
    if (cargo->getArrivalTime() > latestArrivalTime_)
        latestArrivalTime_ = cargo->getArrivalTime();
    return true;
}

bool CargoGroup::removeCargo(const std::string& cargoId) {
    for (auto it = cargos_.begin(); it != cargos_.end(); ++it) {
        if ((*it)->getId() == cargoId) {
            cargos_.erase(it);
            // recompute latestArrivalTime_
            latestArrivalTime_ = "00:00";
            for (auto& c : cargos_) {
                if (c->getArrivalTime() > latestArrivalTime_)
                    latestArrivalTime_ = c->getArrivalTime();
            }
            return true;
        }
    }
    return false;
}

int    CargoGroup::getId() const { return groupId_; }
size_t CargoGroup::size() const { return cargos_.size(); }
bool   CargoGroup::isFull() const { return cargos_.size() >= 10; }
const std::vector<std::shared_ptr<Cargo>>&
CargoGroup::getCargos() const { return cargos_; }
std::string CargoGroup::getDestination() const { return destination_; }
std::string CargoGroup::getLatestArrivalTime() const {
    return latestArrivalTime_;
}
