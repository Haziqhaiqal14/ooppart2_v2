/*****************************************************************************
 * Author:    Haziq Haiqal
 * File:      StatisticsManager.h
 * Purpose:   Compute & display scheduling statistics.
 *****************************************************************************/
#pragma once
#include "Schedule.h"

class StatisticsManager {
public:
    static void report(const Schedule& sched);
};
