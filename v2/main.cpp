#include <iostream>
#include "FreightManager.h"
#include "CargoManager.h"
#include "ScheduleManager.h"
#include "ConsoleUI.h"

string cleanPath(string path) {
    const string trimChars = " \t\n\r\"\'";
    if (path.empty()) return path;
    size_t start = path.find_first_not_of(trimChars);
    size_t end = path.find_last_not_of(trimChars);
    if (start == string::npos) return "";
    return path.substr(start, end - start + 1);
}

int main() {
    cout << "===== INTERNATIONAL FREIGHT CARGO SYSTEM =====" << endl;

    FreightManager fm("");
    CargoManager cm("");
    ScheduleManager sm;

    string freightPath;
    while (true) {
        cout << "Enter freight data file path: ";
        getline(cin, freightPath);
        freightPath = cleanPath(freightPath);
        if (freightPath.empty()) freightPath = "freightData.txt";
        fm.setFilename(freightPath);
        if (fm.loadFile()) break;
        cout << "Error opening file: " << freightPath << endl;
    }

    string cargoPath;
    while (true) {
        cout << "Enter cargo data file path: ";
        getline(cin, cargoPath);
        cargoPath = cleanPath(cargoPath);
        if (cargoPath.empty()) cargoPath = "cargoData.txt";
        cm.setFilename(cargoPath);
        if (cm.loadFile()) break;
        cout << "Error opening file: " << cargoPath << endl;
    }

    while (true) {
        cout << "\n===== MAIN MENU =====" << endl;
        cout << "1. Freight Management" << endl;
        cout << "2. Cargo Management" << endl;
        cout << "3. Schedule Management" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";

        int mainChoice;
        cin >> mainChoice;
        cin.ignore();

        if (mainChoice == 0) break;

        switch (mainChoice) {
        case 1:
            while (true) {
                cout << "\nFREIGHT MANAGEMENT" << endl;
                cout << "1. Add Freight" << endl;
                cout << "2. Edit Freight" << endl;
                cout << "3. Delete Freight" << endl;
                cout << "4. Display All Freights" << endl;
                cout << "5. Save to File" << endl;
                cout << "0. Back" << endl;
                cout << "Enter choice: ";

                int choice;
                cin >> choice;
                cin.ignore();
                if (choice == 0) break;

                switch (choice) {
                case 1: {
                    int idNum = ConsoleUI::getIdInput("Enter Freight ID number: ");
                    string place = ConsoleUI::getPlaceInput("Enter Destination: ");
                    string time = ConsoleUI::getTimeInput("Enter Time (HHMM, 0000-2359): ");
                    fm.addItem(idNum, place, time);
                    break;
                }
                case 2: {
                    int idNum = ConsoleUI::getIdInput("Enter Freight ID number to edit: ");
                    string place = ConsoleUI::getPlaceInput("Enter new Destination: ");
                    string time = ConsoleUI::getTimeInput("Enter new Time (HHMM, 0000-2359): ");
                    fm.editItem(idNum, place, time);
                    break;
                }
                case 3: {
                    int idNum = ConsoleUI::getIdInput("Enter Freight ID number to delete: ");
                    fm.deleteItem(idNum);
                    break;
                }
                case 4: fm.displayAll(); break;
                case 5: fm.writeFile(); break;
                default: cout << "Invalid choice!" << endl;
                }
            }
            break;
        case 2:
            while (true) {
                cout << "\nCARGO MANAGEMENT" << endl;
                cout << "1. Add Cargo" << endl;
                cout << "2. Edit Cargo" << endl;
                cout << "3. Delete Cargo" << endl;
                cout << "4. Display All Cargos" << endl;
                cout << "5. Save to File" << endl;
                cout << "0. Back" << endl;
                cout << "Enter choice: ";

                int choice;
                cin >> choice;
                cin.ignore();
                if (choice == 0) break;

                switch (choice) {
                case 1: {
                    int idNum = ConsoleUI::getIdInput("Enter Cargo ID number: ");
                    string place = ConsoleUI::getPlaceInput("Enter Destination: ");
                    string time = ConsoleUI::getTimeInput("Enter Time (HHMM, 0000-2359): ");
                    cm.addItem(idNum, place, time);
                    break;
                }
                case 2: {
                    int idNum = ConsoleUI::getIdInput("Enter Cargo ID number to edit: ");
                    string place = ConsoleUI::getPlaceInput("Enter new Destination: ");
                    string time = ConsoleUI::getTimeInput("Enter new Time (HHMM, 0000-2359): ");
                    cm.editItem(idNum, place, time);
                    break;
                }
                case 3: {
                    int idNum = ConsoleUI::getIdInput("Enter Cargo ID number to delete: ");
                    cm.deleteItem(idNum);
                    break;
                }
                case 4: cm.displayAll(); break;
                case 5: cm.writeFile(); break;
                default: cout << "Invalid choice!" << endl;
                }
            }
            break;
        case 3:
            while (true) {
                cout << "\nSCHEDULE MANAGEMENT" << endl;
                cout << "1. Display Schedule" << endl;
                cout << "2. Show Unmatched Freights" << endl;
                cout << "3. Show Unmatched Cargos" << endl;
                cout << "4. Save Schedule" << endl;
                cout << "0. Back" << endl;
                cout << "Enter choice: ";

                int choice;
                cin >> choice;
                cin.ignore();
                if (choice == 0) break;

                switch (choice) {
                case 1: sm.displaySchedule(fm, cm); break;
                case 2: sm.displayUnmatchedFreight(fm, cm); break;
                case 3: sm.displayUnmatchedCargo(fm, cm); break;
                case 4: sm.saveScheduleFile(); break;
                default: cout << "Invalid choice." << endl;
                }
            }
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }

    fm.writeFile();
    cm.writeFile();
    cout << "Data saved. Exiting..." << endl;
    return 0;
}