#include <iostream>
#include <iomanip>
#include "Region.h"
#include "City.h"

void PrintCitiesWithMinPopulation(TObject* obj, void* param) {
    if (City* city = dynamic_cast<City*>(obj)) {
        int minPopulation = *(int*)param;
        if (city->GetPopulation() >= minPopulation) {
            std::cout << "  - " << city->GetName()
                << " (" << city->GetPopulation() << " чел.)" << std::endl;
        }
    }
}

void SumPopulation(TObject* obj, void* param) {
    if (City* city = dynamic_cast<City*>(obj)) {
        int* total = (int*)param;
        *total += city->GetPopulation();
    }
}

void FindCityByName(TObject* obj, void* param) {
    if (City* city = dynamic_cast<City*>(obj)) {
        std::pair<std::string, City*>* data = (std::pair<std::string, City*>*)param;
        if (city->GetName() == data->first) {
            data->second = city;
        }
    }
}

int main() {
    std::cout << "=== Лабораторная работа №2. Вариант 30 ===" << std::endl;
    std::cout << "Суммарное количество жителей всех городов в области\n" << std::endl;

    // 1. Создание области (группы)
    std::cout << "1. Создание Московской области..." << std::endl;
    Region* moscowRegion = new Region("Московская область", 44300);

    // 2. Создание городов
    std::cout << "2. Создание городов..." << std::endl;
    City* moscow = new City("Москва", 2561, 12600000);
    City* balashikha = new City("Балашиха", 244, 507307);
    City* khimki = new City("Химки", 109, 257128);
    City* podolsk = new City("Подольск", 338, 309250);
    City* korolev = new City("Королёв", 51, 225299);

    // 3. Добавление городов в область
    std::cout << "3. Добавление городов в область..." << std::endl;
    moscowRegion->Insert(moscow);
    moscowRegion->Insert(balashikha);
    moscowRegion->Insert(khimki);
    moscowRegion->Insert(podolsk);
    moscowRegion->Insert(korolev);

    // 4. Просмотр содержимого области
    std::cout << "\n4. Содержимое Московской области:" << std::endl;
    moscowRegion->Show();

    // 5. Использование итератора для поиска городов с населением > 300000
    std::cout << "\n5.Города с населением более 300,000 человек:" << std::endl;
    int minPop = 300000;
    moscowRegion->ForEach(PrintCitiesWithMinPopulation, &minPop);

    // 6. Расчет суммарного населения (вариант 30)
    std::cout << "\n6. Расчет суммарного населения (вариант 30):" << std::endl;

    // Способ 1: через итератор
    int totalPopulation = 0;
    moscowRegion->ForEach(SumPopulation, &totalPopulation);
    std::cout << "Суммарное население всех городов: "
        << std::fixed << std::setprecision(0) << totalPopulation << " чел." << std::endl;

    // Способ 2: через специальный метод
    int total2 = moscowRegion->GetTotalPopulation();
    std::cout << "Проверка (через GetTotalPopulation): " << total2 << " чел." << std::endl;

    // 7. Работа с методами группы
    std::cout << "\n7. Демонстрация работы методов группы:" << std::endl;

    // Проверка на пустоту
    std::cout << "Область пуста? " << (moscowRegion->Empty() ? "Да" : "Нет") << std::endl;

    // Поиск и удаление города
    std::cout << "\nУдаление города Королёв..." << std::endl;
    std::pair<std::string, City*> searchData("Королёв", nullptr);
    moscowRegion->ForEach(FindCityByName, &searchData);

    if (searchData.second) {
        moscowRegion->DelDisp(searchData.second);
        std::cout << "Город Королёв удален." << std::endl;
    }

    // Обновленная информация
    std::cout << "\n8. Обновленная информация об области:" << std::endl;
    moscowRegion->Show();

    int updatedTotal = moscowRegion->GetTotalPopulation();
    std::cout << "\nСуммарное население после удаления: " << updatedTotal << " чел." << std::endl;

    // 9. Создание копии области
    std::cout << "\n9. Создание копии области (конструктор копирования):" << std::endl;
    Region* copyRegion = new Region(*moscowRegion);
    copyRegion->SetName("Копия Московской области");
    copyRegion->Show();

    // 10. Очистка памяти
    std::cout << "\n10. Очистка памяти..." << std::endl;
    delete moscowRegion;
    delete copyRegion;

    // Городы уже удалены через DelDisp, но проверим, что всё чисто
    std::cout << "Программа завершена успешно!" << std::endl;

    return 0;
}
