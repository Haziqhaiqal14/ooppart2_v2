#include "TimeUtils.h"

int TimeUtils::toMinutes(const std::string& timeStr) {
    if (timeStr.length() != 4)
        throw std::invalid_argument("Invalid time format");

    int hours = std::stoi(timeStr.substr(0, 2));
    int minutes = std::stoi(timeStr.substr(2, 2));

    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
        throw std::out_of_range("Invalid time value");

    return hours * 60 + minutes;
}

std::string TimeUtils::normalizeTime(const std::string& input) {
    std::string clean = input;
    // Remove spaces
    clean.erase(std::remove(clean.begin(), clean.end(), ' '), clean.end());
    // Convert to lowercase
    std::transform(clean.begin(), clean.end(), clean.begin(),
        [](unsigned char c) { return std::tolower(c); });

    // Handle AM/PM formats
    size_t amPos = clean.find("am");
    size_t pmPos = clean.find("pm");
    bool hasAM = (amPos != std::string::npos);
    bool hasPM = (pmPos != std::string::npos);

    if (hasAM || hasPM) {
        // Extract time part
        std::string timePart = hasAM ? clean.substr(0, amPos) : clean.substr(0, pmPos);

        // Handle colon separator
        size_t colonPos = timePart.find(':');
        int hours = 0, minutes = 0;

        if (colonPos != std::string::npos) {
            hours = std::stoi(timePart.substr(0, colonPos));
            minutes = std::stoi(timePart.substr(colonPos + 1));
        }
        else if (timePart.length() >= 3) {
            // Handle formats like 730am, 1230pm
            hours = std::stoi(timePart.substr(0, timePart.length() - 2));
            minutes = std::stoi(timePart.substr(timePart.length() - 2));
        }
        else {
            throw std::invalid_argument("Invalid time format: " + input);
        }

        // Validate 12-hour format
        if (hours < 1 || hours > 12) {
            throw std::invalid_argument("Invalid hours in 12-hour format");
        }

        // Convert 12-hour to 24-hour format
        if (hasPM && hours < 12) hours += 12;
        if (hasAM && hours == 12) hours = 0;

        // Format as HHMM
        char buffer[5];
        snprintf(buffer, sizeof(buffer), "%02d%02d", hours, minutes);
        return std::string(buffer);
    }

    // Assume already in HHMM format
    if (clean.length() == 4 &&
        std::all_of(clean.begin(), clean.end(), ::isdigit)) {
        return clean;
    }

    throw std::invalid_argument("Invalid time format: " + input);
}