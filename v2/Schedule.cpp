#include <vector>
#include <utility>

using namespace std;

#include "Schedule.h"

void Schedule::setMatch(const Freight& f, const Cargo& c) {
    matches.push_back(make_pair(f, c));
}

const vector<pair<Freight, Cargo>>& Schedule::getMatches() const {
    return matches;
}

void Schedule::clearMatches() {
    matches.clear();
}
