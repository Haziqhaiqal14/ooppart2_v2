#pragma once
#include <vector>
#include <utility>

#include "Freight.h"
#include "Cargo.h"

class Schedule {
private:
    vector<pair<Freight, Cargo>> matches;
public:
    void setMatch(const Freight& f, const Cargo& c);
    const vector<pair<Freight, Cargo>>& getMatches() const;
    void clearMatches();
};
