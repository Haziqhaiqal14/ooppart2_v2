#pragma once
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cctype>

class TimeUtils {
public:
    static int toMinutes(const std::string& timeStr);
    static std::string normalizeTime(const std::string& input);
};