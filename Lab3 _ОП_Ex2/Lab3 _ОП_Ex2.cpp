#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;
void arr_cout(int[100][100], int, int);
void arr_cout(int*, int);

int main()
{
    SetConsoleOutputCP(1251);
    int n = 0, m = 0, t = 0;
    int arr[100][100]
    {
    {1, -29, 3, -41},
    {-5, 6, -7, 8},
    {9, -10, 11, -12},
    {-13, 14, -15, 16},
    };
    int arr_h[100];
    cout << "Введіть 1 якщо хочете ввести свій масий\nВведіть будь який інший символ якщо хочете продовжити з наявним (тестовим) масивом\n!!! Тестовий масив за замовчуванням має розмірнысть 4x4\n";
    cin >> t;
    cout << '\n';
    if (1 == t)
    {
        cout << "Введіть розмірність масиву NxM" << '\n';
        cout << "N= "; cin >> n;
        cout << "M= "; cin >> m;
        cout << "Введіть масив " << n << "x" << m << '\n';
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    else
    {
        n = 4;
        m = 4;
    }
    cout << "Наявний масив: " << '\n';
    arr_cout(arr, n, m);
    for (size_t i = 0; i < n; i++)
    {
        arr_h[i] = 0;
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            if ((arr[i][j] < 0) && 1 == abs(arr[i][j] % 2))
            {
                arr_h[j] += abs(arr[i][j]);
            }
    }
    cout << "Модулі наявних стовпців: " << '\n';
    arr_cout(arr_h, n);
    cout << '\n';
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0, x = 0; j < n; j++)
        {
            if (arr_h[j] > arr_h[i])
            {
                x = arr_h[i];
                arr_h[i] = arr_h[j];
                arr_h[j] = x;
                for (size_t k = 0; k < m; k++)
                {
                    x = arr[k][j];
                    arr[k][j] = arr[k][i];
                    arr[k][i] = x;
                }
            }
        }
    }
    cout << '\n' << "Відсортований масив" << n << "x" << m << '\n';
    arr_cout(arr, n, m);
    cout << "Модулі наявних стовпців: " << '\n';
    arr_cout(arr_h, n);
    cout << "\n\n";
    cout << "Характеристика наведених стовпців: \nЯкщо всі цифри = 0 то у масиві не має відємних непарних елементів, тобто за умовою його не можна сортувати" << '\n';
    arr_cout(arr_h, n);
}

void arr_cout(int arr[100][100], int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }
}

void arr_cout(int arr_h[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr_h[i] << '\t';
    }
}