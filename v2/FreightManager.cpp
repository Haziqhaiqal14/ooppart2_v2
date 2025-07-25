#include "FreightManager.h"

void FreightManager::addItem(int idNum, string place, string time) {
    string id = formatId(idNum);
    if (idExists(id)) {
        cout << "ID already exists." << endl;
        return;
    }
    items.push_back(Freight(id, place, time));
    cout << "Freight added successfully." << endl;
}

void FreightManager::editItem(int idNum, string place, string time) {
    string id = formatId(idNum);
    for (auto& item : items) {
        if (item.getId() == id) {
            item.setPlace(place);
            item.setTime(time);
            cout << "Freight updated successfully." << endl;
            return;
        }
    }
    cout << "Freight not found." << endl;
}

void FreightManager::deleteItem(int idNum) {
    string id = formatId(idNum);
    auto it = remove_if(items.begin(), items.end(),
        [id](const Freight& f) { return f.getId() == id; });
    if (it != items.end()) {
        items.erase(it, items.end());
        cout << "Freight deleted successfully." << endl;
    }
    else {
        cout << "Freight not found." << endl;
    }
}