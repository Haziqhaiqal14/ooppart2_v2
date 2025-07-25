/*****************************************************************************
 * Author:    Haziq Haiqal
 * File:      Assignment.cpp
 * Purpose:   Implementation of Assignment.
 *****************************************************************************/
#include "Assignment.h"

Assignment::Assignment(std::shared_ptr<Freight> f, std::shared_ptr<Cargo> c)
    : freight_(f), cargo_(c) {
}

std::shared_ptr<Cargo>   Assignment::getCargo()  const { return cargo_; }
std::shared_ptr<Freight> Assignment::getFreight() const { return freight_; }

std::string Assignment::toString() const {
    return freight_->getId() + " <- " + cargo_->getId();
}
