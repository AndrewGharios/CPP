#include "Region.h"
#include <iostream>

Region::Region(const std::string& n, double a)
    : name(n), area(a), items(nullptr) {}

Region::Region(const Region& other)
    : name(other.name), area(other.area), items(nullptr) {
    // Копирование элементов
    TItem* current = other.items;
    while (current != nullptr) {
        if (City* city = dynamic_cast<City*>(current->item)) {
            Insert(new City(city->GetName(), city->GetArea(), city->GetPopulation()));
        }
        current = current->next;
    }
}

Region::~Region() {
    while (items != nullptr) {
        TItem* temp = items;
        items = items->next;
        delete temp->item;
        delete temp;
    }
}

void Region::Show() const {
    std::cout << "Область: " << name << ", Площадь: " << area << " кв.км" << std::endl;
    std::cout << "Города в области:" << std::endl;

    TItem* current = items;
    int count = 1;
    while (current != nullptr) {
        std::cout << count++ << ". ";
        current->item->Show();
        current = current->next;
    }
}

std::string Region::GetName() const {
    return name;
}

void Region::SetName(const std::string& n) {
    name = n;
}

void Region::SetArea(double a) {
    area = a;
}

double Region::GetArea() const {
    return area;
}

void Region::Insert(TObject* p) {
    TItem* newItem = new TItem;
    newItem->item = p;
    newItem->next = items;
    items = newItem;
}

bool Region::Empty() const {
    return items == nullptr;
}

TObject* Region::Delete(TObject* p) {
    if (items == nullptr) return nullptr;

    TItem* current = items;
    TItem* prev = nullptr;

    while (current != nullptr) {
        if (current->item == p) {
            if (prev == nullptr) {
                items = current->next;
            }
            else {
                prev->next = current->next;
            }
            TObject* deleted = current->item;
            delete current;
            return deleted;
        }
        prev = current;
        current = current->next;
    }
    return nullptr;
}

void Region::DelDisp(TObject* p) {
    TObject* deleted = Delete(p);
    if (deleted) {
        delete deleted;
    }
}

void Region::ForEach(ActionFunc action, void* param) {
    TItem* current = items;
    while (current != nullptr) {
        action(current->item, param);
        current = current->next;
    }
}

int Region::GetTotalPopulation() const {
    int total = 0;
    TItem* current = items;

    while (current != nullptr) {
        if (City* city = dynamic_cast<City*>(current->item)) {
            total += city->GetPopulation();
        }
        current = current->next;
    }

    return total;
}