#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
class BaseShipmentManager {
protected:
    string filename;
    vector<T> items;

    // Pure virtual functions for ID formatting and type names
    virtual string formatId(int idNum) const = 0;
    virtual string getTypeName() const = 0;

public:
    BaseShipmentManager(string filename) : filename(filename) {}
    virtual ~BaseShipmentManager() = default;

    void setFilename(string newFilename) { filename = newFilename; }

    bool loadFile() {
        ifstream file(filename);
        if (!file.is_open()) return false;

        items.clear();
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, place, time;
            getline(ss, id, ',');
            getline(ss, place, ',');
            getline(ss, time);
            items.push_back(T(id, place, time));
        }
        file.close();
        cout << "Loaded " << items.size() << " records from " << filename << endl;
        return true;
    }

    void writeFile() {
        ofstream file(filename);
        for (const auto& item : items) {
            file << item.getId() << "," << item.getPlace() << "," << item.getTime() << endl;
        }
        file.close();
        cout << "Data saved to " << filename << endl;
    }

    void displayAll() const {
        if (items.empty()) {
            cout << "No records available." << endl;
            return;
        }
        for (const auto& item : items) {
            item.display();
        }
    }

    const vector<T>& getItems() const { return items; }

    bool idExists(string id) const {
        for (const auto& item : items) {
            if (item.getId() == id) return true;
        }
        return false;
    }

    // Refactored shared functions
    void addItem(int idNum, string place, string time) {
        string id = formatId(idNum);
        if (idExists(id)) {
            cout << "ID already exists." << endl;
            return;
        }
        items.push_back(T(id, place, time));
        cout << getTypeName() << " added successfully." << endl;
    }

    void editItem(int idNum, string place, string time) {
        string id = formatId(idNum);
        for (auto& item : items) {
            if (item.getId() == id) {
                item.setPlace(place);
                item.setTime(time);
                cout << getTypeName() << " updated successfully." << endl;
                return;
            }
        }
        cout << getTypeName() << " not found." << endl;
    }

    void deleteItem(int idNum) {
        string id = formatId(idNum);
        auto it = remove_if(items.begin(), items.end(),
            [id](const T& item) { return item.getId() == id; });
        if (it != items.end()) {
            items.erase(it, items.end());
            cout << getTypeName() << " deleted successfully." << endl;
        }
        else {
            cout << getTypeName() << " not found." << endl;
        }
    }
};