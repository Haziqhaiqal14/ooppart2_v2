#pragma once
#include <iostream>
#include <string>
#include "InputValidator.h"

using namespace std;

class ConsoleUI {
public:
    static int getIdInput(const string& prompt);
    static string getPlaceInput(const string& prompt);
    static string getTimeInput(const string& prompt);
};