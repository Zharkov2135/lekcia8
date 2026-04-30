#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void printArrayLine(const int* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) cout << ", ";
    }
    cout << " ]\n";
}

void printTitle(const string& title) {
    cout << "\n========================================\n";
    cout << title << "\n";
    cout << "========================================\n";
}

int main() {
#ifdef _WIN32
    // Вмикаємо UTF-8 для консолі Windows (щоб українська не ламалась)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int init[] = { 0, 1, 3, 4, 5, 2, 1, -4, -1, 10, 55 };
    int size = 11;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = init[i];

    printTitle("Початковий масив");
    printArrayLine(arr, size);

    // ---------- ПЕРЕБІР МАСИВУ ----------
    printTitle("Блок 1. Вивести всі елементи масиву");
    printArrayLine(arr, size);

    printTitle("Блок 2. Вивести всі елементи у зворотному порядку");
    cout << "[ ";
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i];
        if (i != 0) cout << ", ";
    }
    cout << " ]\n";

    printTitle("Блок 3. Вивести парні елементи масиву");
    cout << "[ ";
    bool first = true;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            if (!first) cout << ", ";
            cout << arr[i];
            first = false;
        }
    }
    cout << " ]\n";

    printTitle("Блок 4. Вивести елементи масиву через один (індекси 0,2,4...)");
    cout << "[ ";
    first = true;
    for (int i = 0; i < size; i += 2) {
        if (!first) cout << ", ";
        cout << arr[i];
        first = false;
    }
    cout << " ]\n";

    printTitle("Блок 5. Вивести елементи до тих пір, доки не зустрінеться -1");
    cout << "[ ";
    first = true;
    for (int i = 0; i < size; i++) {
        if (arr[i] == -1) break;
        if (!first) cout << ", ";
        cout << arr[i];
        first = false;
    }
    cout << " ]\n";

    // ---------- ДОДАВАННЯ ТА ВИДАЛЕННЯ ----------
    int value = 10;

    // Блок 1. Додати елемент в кінець
    {
        int* newArr = new int[size + 1];
        for (int i = 0; i < size; i++) newArr[i] = arr[i];
        newArr[size] = value;

        delete[] arr;
        arr = newArr;
        size++;

        printTitle("Блок 6. Додати елемент в кінець (value=10)");
        printArrayLine(arr, size);
    }

    // Блок 2. Додати елемент на початок
    {
        int* newArr = new int[size + 1];
        newArr[0] = value;
        for (int i = 0; i < size; i++) newArr[i + 1] = arr[i];

        delete[] arr;
        arr = newArr;
        size++;

        printTitle("Блок 7. Додати елемент на початок (value=10)");
        printArrayLine(arr, size);
    }

    // Блок 3. Додати елемент в позицію (наприклад 4)
    {
        int position = 4; // 0-based
        if (position < 0) position = 0;
        if (position > size) position = size;

        int* newArr = new int[size + 1];
        for (int i = 0, j = 0; i < size + 1; i++) {
            if (i == position) newArr[i] = value;
            else newArr[i] = arr[j++];
        }

        delete[] arr;
        arr = newArr;
        size++;

        printTitle("Блок 8. Додати елемент у позицію 4 (value=10)");
        printArrayLine(arr, size);
    }

    // Блок 4. Видалити елемент з кінця
    {
        int* newArr = new int[size - 1];
        for (int i = 0; i < size - 1; i++) newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
        size--;

        printTitle("Блок 9. Видалити елемент з кінця");
        printArrayLine(arr, size);
    }

    // Блок 5. Видалити елемент з початку
    {
        int* newArr = new int[size - 1];
        for (int i = 1; i < size; i++) newArr[i - 1] = arr[i];

        delete[] arr;
        arr = newArr;
        size--;

        printTitle("Блок 10. Видалити елемент з початку");
        printArrayLine(arr, size);
    }

    // Блок 6. Видалити елемент з позиції (наприклад 5)
    {
        int position = 5; // 0-based
        if (position < 0) position = 0;
        if (position >= size) position = size - 1;

        int* newArr = new int[size - 1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i == position) continue;
            newArr[j++] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        size--;

        printTitle("Блок 11. Видалити елемент з позиції 5");
        printArrayLine(arr, size);
    }

    // Блок 7. Створення масиву з двох масивів
    {
        int a1[] = { 1, 2, 3 };
        int a2[] = { 4, 5, 6 };
        int n1 = 3, n2 = 3;

        int* merged = new int[n1 + n2];
        for (int i = 0; i < n1; i++) merged[i] = a1[i];
        for (int i = 0; i < n2; i++) merged[n1 + i] = a2[i];

        printTitle("Блок 12. Об'єднати два масиви [1,2,3] та [4,5,6]");
        printArrayLine(merged, n1 + n2);

        delete[] merged;
    }

    delete[] arr;
    return 0;
}
