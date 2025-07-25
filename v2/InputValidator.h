#pragma once
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

class InputValidator {
public:
    static int validateId(const string& input);
    static string validatePlace(const string& input);
    static string validateTime(const string& input);
};