#include "TimePriorityStrategy.h"
#include <algorithm>

void TimePriorityStrategy::schedule(FreightManager& fm,
    CargoManager& cm,
    Schedule& schedule) {
    // Get sorted lists (by time)
    auto freights = fm.getItems();
    auto cargos = cm.getItems();

    std::sort(cargos.begin(), cargos.end(),
        [](const auto& a, const auto& b) {
            return a->getTime() < b->getTime();
        });

    std::sort(freights.begin(), freights.end(),
        [](const auto& a, const auto& b) {
            return a->getTime() < b->getTime();
        });

    // Assign cargos to freights based on time window
    for (const auto& cargo : cargos) {
        for (const auto& freight : freights) {
            if (freight->canLoad() &&
                freight->getDestination() == cargo->getDestination() &&
                TimeWindowValidator::isValid(freight->getTime(), cargo->getTime())) {

                schedule.addAssignment(freight, cargo);
                freight->addCargo();
                break;
            }
        }
    }
}