#include <iostream>
#include <sstream>

#include "InputValidator.h"

int InputValidator::validateId(const string& input) {
    stringstream ss(input);
    int value;
    if (ss >> value) {
        if (value < 0) {
            throw invalid_argument("Input cannot be negative");
        }
        char c;
        if (ss >> c) {
            throw invalid_argument("Extra characters detected");
        }
        return value;
    }
    throw invalid_argument("Invalid integer input");
}

string InputValidator::validatePlace(const string& input) {
    if (input.empty()) {
        throw invalid_argument("Place cannot be blank");
    }

    for (char c : input) {
        if (!isalpha(c) && c != ' ') {
            throw invalid_argument("Only alphabets and spaces allowed");
        }
    }
    return input;
}

string InputValidator::validateTime(const string& input) {
    string time = input;
    time.erase(remove(time.begin(), time.end(), ' '), time.end());

    if (time.empty()) {
        throw invalid_argument("Time cannot be blank");
    }

    if (time.length() != 4) {
        throw invalid_argument("Must be 4 digits (HHMM)");
    }

    for (char c : time) {
        if (!isdigit(c)) {
            throw invalid_argument("Only digits allowed");
        }
    }

    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(2, 2));

    if (hours < 0 || hours > 23) {
        throw invalid_argument("Hours must be 00-23");
    }

    if (minutes < 0 || minutes > 59) {
        throw invalid_argument("Minutes must be 00-59");
    }

    return time;
}