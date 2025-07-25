#include "ConsoleUI.h"

int ConsoleUI::getIdInput(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        try {
            return InputValidator::validateId(input);
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << ". Please try again." << endl;
        }
    }
}

string ConsoleUI::getPlaceInput(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        try {
            return InputValidator::validatePlace(input);
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << ". Please try again." << endl;
        }
    }
}

string ConsoleUI::getTimeInput(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        try {
            return InputValidator::validateTime(input);
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << ". Please try again." << endl;
        }
    }
}