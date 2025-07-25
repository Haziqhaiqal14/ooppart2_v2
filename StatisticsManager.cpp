/*****************************************************************************
 * Author:    Haziq Haiqal
 * File:      StatisticsManager.cpp
 * Purpose:   Implementation of scheduling statistics.
 *****************************************************************************/
#include "StatisticsManager.h"
#include <iostream>
#include <map>

void StatisticsManager::report(const Schedule& sched) {
    const auto& assigns = sched.getAssignments();
    std::map<std::string, int> loadMap, capMap;
    for (auto& a : assigns) {
        auto fid = a.getFreight()->getId();
        loadMap[fid] += a.getCargo()->getSize();
        capMap[fid] = a.getFreight()->getCapacity();
    }
    if (loadMap.empty()) {
        std::cout << "No assignments to report.\n";
        return;
    }
    double sumPct = 0.0;
    std::cout << "\n=== Utilization Stats ===\n";
    for (auto& [fid, load] : loadMap) {
        int cap = capMap[fid];
        double pct = (100.0 * load) / cap;
        sumPct += pct;
        std::cout << "Freight " << fid
            << ": " << load << "/" << cap
            << " (" << pct << "%)\n";
    }
    std::cout << "Average utilization: "
        << (sumPct / loadMap.size())
        << "%\n";
}
