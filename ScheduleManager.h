#pragma once
#include <vector>
#include "BaseManager.h"
#include "Schedule.h"

class ScheduleManager {
private:
    Schedule schedule;

public:
    void displaySchedule(const FreightManager& fm, const CargoManager& cm);
    void displayUnmatchedFreight(const FreightManager& fm, const CargoManager& cm);
    void displayUnmatchedCargo(const FreightManager& fm, const CargoManager& cm);
    void saveScheduleFile();
};