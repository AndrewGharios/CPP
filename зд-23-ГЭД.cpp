#include <math.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() {
    const char* filename = "numbers.txt";
    int N;

    setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    std::cout << "Введите количество чисел: ";
    std::cin >> N;

    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Запись случайных чисел в файл
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи.\n";
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        double num = (std::rand() % 10000) / 100.0; // Генерация числа от 0.00 до 99.99
        outFile << num << '\n';
    }

    outFile.close();

    // Чтение чисел из файла и поиск min и max
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Ошибка открытия файла для чтения.\n";
        return 1;
    }

    double number, minVal = std::numeric_limits<double>::max();
    double maxVal = std::numeric_limits<double>::lowest();

    while (inFile >> number) {
        if (number < minVal) minVal = number;
        if (number > maxVal) maxVal = number;
    }

    inFile.close();

    double sum = minVal + maxVal;

    std::cout << "Минимальное значение: " << minVal << "\n";
    std::cout << "Максимальное значение: " << maxVal << "\n";
    std::cout << "Сумма минимального и максимального: " << sum << "\n";

    return 0;
}