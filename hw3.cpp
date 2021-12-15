// код написан на C++
#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <iomanip>

using namespace std;
int main()
{
    system("chcp 1251");
    system("cls");

    srand(time(NULL)); // устанавливаем стартовое значение для рандома

    cout << "Работу выполнил Жигалин Данил Вадимович гр. 421-1\n" << endl;
    cout << "Введите размерность массива: ";

    unsigned count = 0,
             n;
    cin >> n;

    int* mass = new int[n];

    cout << "Изначальный массив:     ";
    for (unsigned i = 0; i < n; i++)
    {
        mass[i] = rand();
        cout << setw(5) << mass[i] << " ";
    }

    cout << endl;

    for (unsigned i = 0; i < n; i++)
    {
        bool flag = false;

        for (unsigned j = 0; j < n - i - 1; j++)
        {
            if (mass[j] > mass[j + 1])
            {
                int elem = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = elem;

                flag = true; count++;
            }
        }

        if (!flag)
            break;
    }

    cout << "Преобразованный массив: ";
    for (unsigned i = 0; i < n; i++)
        cout << setw(5) << mass[i] << " ";

    cout << endl;
    cout << "Всего перестановок: " << count << endl;
}