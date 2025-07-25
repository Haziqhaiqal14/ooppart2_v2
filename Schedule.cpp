#include "Schedule.h"
#include <fstream>
#include <iostream>

void Schedule::addAssignment(std::shared_ptr<Freight> freight,
    std::shared_ptr<Cargo> cargo) {
    assignments.push_back(std::make_pair(freight, cargo));
}

void Schedule::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& assignment : assignments) {
        file << assignment.first->getId() << ","
            << assignment.second->getId() << ","
            << assignment.first->getDestination() << ","
            << assignment.first->getTime() << "\n";
    }
    file.close();
}

void Schedule::display() const {
    if (assignments.empty()) {
        std::cout << "No assignments in schedule." << std::endl;
        return;
    }

    for (const auto& assignment : assignments) {
        std::cout << "Freight: " << assignment.first->getId();
        std::cout << " -> Cargo: " << assignment.second->getId();
        std::cout << " | Dest: " << assignment.first->getDestination();
        std::cout << " | Time: " << assignment.first->getTime() << std::endl;
    }
}