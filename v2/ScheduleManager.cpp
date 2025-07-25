// ScheduleManager.h (updated)
#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include "BaseShipmentManager.h"
#include "Schedule.h"
#include "Freight.h"
#include "Cargo.h"
#include "CargoGroup.h"

class SchedulingStrategy {
public:
    virtual ~SchedulingStrategy() = default;
    virtual void schedule(FreightManager& fm, CargoManager& cm,
        std::vector<CargoGroup>& groups, Schedule& schedule) = 0;
};

class TimePriorityStrategy : public SchedulingStrategy {
public:
    void schedule(FreightManager& fm, CargoManager& cm,
        std::vector<CargoGroup>& groups, Schedule& schedule) override;
};

class EfficiencyPriorityStrategy : public SchedulingStrategy {
public:
    void schedule(FreightManager& fm, CargoManager& cm,
        std::vector<CargoGroup>& groups, Schedule& schedule) override;
};

class ScheduleManager {
private:
    Schedule schedule;
    std::vector<CargoGroup> cargoGroups;
    std::unique_ptr<SchedulingStrategy> currentStrategy;

public:
    ScheduleManager();

    // Display functions
    void displaySchedule(const FreightManager& fm, const CargoManager& cm) const;
    void displayScheduleByArrivalTime(const FreightManager& fm, const CargoManager& cm) const;
    void displayScheduleByFreightCapacity(const FreightManager& fm) const;
    void displayUnmatchedFreight(const FreightManager& fm) const;
    void displayUnmatchedCargo(const CargoManager& cm) const;

    // Group management
    void createCargoGroup(const std::vector<std::string>& cargoIds, CargoManager& cm);
    void splitCargoGroup(int groupId, CargoManager& cm);

    // Scheduling operations
    void setSchedulingStrategy(std::unique_ptr<SchedulingStrategy> strategy);
    void performScheduling(FreightManager& fm, CargoManager& cm);

    // File operations
    void saveScheduleFile(const std::string& filename,
        const FreightManager& fm,
        const CargoManager& cm) const;
    void saveCurrentData(const std::string& freightFile,
        const std::string& cargoFile,
        const FreightManager& fm,
        const CargoManager& cm) const;
};