#include "Place.h"
#include "Region.h"
#include "City.h"
#include "Metropolis.h"
#include <iostream>
#include <windows.h>

int main() {

    setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    std::cout << "\n1. Создание объектов..." << std::endl;
    Place* park = new Place("Центральный парк", 3.41);
    Region* moscowRegion = new Region("Московская область", 44300, 36);
    City* moscow = new City("Москва", 2561, 12600000);
    Metropolis* ny = new Metropolis("Нью-Йорк", 1214, 8419000, 284);
    
    std::cout << "\n2. Просмотр списка через виртуальные функции:" << std::endl;
    Location::PrintList();

    std::cout << "\n3. Демонстрация полиморфизма через массив указателей:" << std::endl;
    Location* locations[] = {park, moscowRegion, moscow, ny};
    
    for (int i = 0; i < 4; i++) {
        locations[i]->Show();
    }

    std::cout << "\n4. Прямой вызов методов (без виртуальности):" << std::endl;
    if (park) park->Place::Show();
    if (moscowRegion) moscowRegion->Region::Show();
    if (moscow) moscow->City::Show();
    if (ny) ny->Metropolis::Show();

    std::cout << "\n5. Очистка памяти..." << std::endl;
    Location::ClearList();
    
    std::cout << "\n6. Проверка что список пуст:" << std::endl;
    Location::PrintList();
    
    return 0;
}