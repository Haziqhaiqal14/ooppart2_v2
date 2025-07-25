/*****************************************************************************
 * Author:    Haziq Haiqal
 * File:      Assignment.h
 * Purpose:   Represents a Cargo → Freight assignment.
 *****************************************************************************/
#pragma once
#include <memory>
#include "Cargo.h"
#include "Freight.h"

class Assignment {
private:
    std::shared_ptr<Freight> freight_;
    std::shared_ptr<Cargo>   cargo_;
public:
    Assignment(std::shared_ptr<Freight> f, std::shared_ptr<Cargo> c);
    std::shared_ptr<Cargo>   getCargo()  const;
    std::shared_ptr<Freight> getFreight() const;
    std::string              toString()  const;
};
