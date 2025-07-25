#include "CargoManager.h"

void CargoManager::addItem(int idNum, string place, string time) {
    string id = formatId(idNum);
    if (idExists(id)) {
        cout << "ID already exists." << endl;
        return;
    }
    items.push_back(Cargo(id, place, time));
    cout << "Cargo added successfully." << endl;
}

void CargoManager::editItem(int idNum, string place, string time) {
    string id = formatId(idNum);
    for (auto& item : items) {
        if (item.getId() == id) {
            item.setPlace(place);
            item.setTime(time);
            cout << "Cargo updated successfully." << endl;
            return;
        }
    }
    cout << "Cargo not found." << endl;
}

void CargoManager::deleteItem(int idNum) {
    string id = formatId(idNum);
    auto it = remove_if(items.begin(), items.end(),
        [id](const Cargo& c) { return c.getId() == id; });
    if (it != items.end()) {
        items.erase(it, items.end());
        cout << "Cargo deleted successfully." << endl;
    }
    else {
        cout << "Cargo not found." << endl;
    }
}