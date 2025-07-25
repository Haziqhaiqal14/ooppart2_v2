// Cargo.h (extending Shipment)
#pragma once
#include "Shipment.h"

class Cargo : public Shipment {
private:
    int groupId; // 0 means not in a group
    bool assigned;

public:
    Cargo(const std::string& id, const std::string& place, const std::string& time, int group = 0);

    // Group management
    int getGroupId() const;
    void setGroupId(int group);
    bool isInGroup() const;

    // Assignment status
    bool isAssigned() const;
    void setAssigned(bool status);

    // Comparison for grouping
    bool canGroupWith(const Cargo& other) const;

    void display() const override;
};