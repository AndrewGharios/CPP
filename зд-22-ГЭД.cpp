#include <math.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <unordered_set>

bool hasDuplicates(const std::vector<int>& L) {
    std::unordered_set<int> seen;
    for (int num : L) {
        if (seen.count(num)) {
            return true; // Найден дубликат
        }
        seen.insert(num);
    }
    return false; // Дубликатов нет
}

int main() {
    std::vector<int> L;
    int n, element;

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    std::cout << "Введите количество элементов в списке: ";
    std::cin >> n;

    std::cout << "Введите элементы списка:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> element;
        L.push_back(element);
    }

    if (hasDuplicates(L)) {
        std::cout << "В списке есть одинаковые элементы.\n";
    } else {
        std::cout << "Все элементы списка уникальны.\n";
    }

    return 0;
}