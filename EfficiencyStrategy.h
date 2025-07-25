#pragma once
#include "ISchedulingStrategy.h"
#include "TimeWindowValidator.h"
#include <algorithm>

class EfficiencyStrategy : public ISchedulingStrategy {
public:
    void schedule(FreightManager& fm, CargoManager& cm, Schedule& schedule) override;
    std::string getName() const override { return "Efficiency Scheduling"; }
};