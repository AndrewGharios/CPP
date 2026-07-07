#include "Location.h"

Location* Location::begin = nullptr;

Location::Location(const std::string& n, double a) 
    : name(n), area(a), next(nullptr) {
    AddToList();
}

Location::~Location() {}

void Location::AddToList() {
    next = begin;
    begin = this;
}

void Location::PrintList() {
    Location* current = begin;
    while (current != nullptr) {
        current->Show();
        current = current->next;
    }
}

void Location::ClearList() {
    while (begin != nullptr) {
        Location* temp = begin;
        begin = begin->next;
        delete temp;
    }
}