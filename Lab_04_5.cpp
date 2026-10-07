#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <windows.h> // Потрібно для налаштування кодування консолі Windows

using namespace std;

int main()
{
    // Налаштування UTF-8 кодування для консолі Windows (65001 замість 1251)
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double R, x, y;

    cout << "=== Завдання 4.5 (Варіант 3) ===" << endl;
    cout << "Введіть значення радіуса R: ";
    cin >> R;

    // Ініціалізація генератора випадкових чисел від системного таймера
    srand((unsigned)time(NULL));

    cout << "\n--- Спосіб 1: Ручне введення координат (10 пострілів) ---" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Постріл " << i + 1 << " (x y): ";
        cin >> x >> y;

        // Перевірка належності точки замальованій області
        if ((x >= 0 && y >= 0 && x * x + y * y <= R * R) ||
            (x <= 0 && y <= 0 && y >= -x - R))
        {
            cout << "Результат: yes (попадання)" << endl;
        }
        else
        {
            cout << "Результат: no (промах)" << endl;
        }
    }

    cout << "\n--- Спосіб 2: Генерація випадкових координат x, y in [-2R; 2R] ---" << endl;
    cout << fixed << setprecision(4);

    for (int i = 0; i < 10; i++)
    {
        // Генерація дійсного числа x та y в діапазоні [-2R; 2R]
        x = (4.0 * R * rand() / RAND_MAX) - 2.0 * R;
        y = (4.0 * R * rand() / RAND_MAX) - 2.0 * R;

        cout << "x = " << setw(8) << x << " | y = " << setw(8) << y << " | ";

        if ((x >= 0 && y >= 0 && x * x + y * y <= R * R) ||
            (x <= 0 && y <= 0 && y >= -x - R))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}