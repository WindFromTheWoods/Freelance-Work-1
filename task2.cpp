#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void replaceUpperHalfWithMin(int** arr, int n) {
    // Найдем минимальное значение в массиве
    int min = arr[0][0];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }

    // Подсчитаем количество элементов в верхней половине и заменим их на минимальное значение
    int count = 0;
    for(int i = 0; i < n/2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            count++;
            arr[i][j] = min;
        }
    }

    cout << "Number of elements in upper half: " << count << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " "; // выводим
        }
        cout << endl;
    }
}

int countZerosInLowerHalf(int **arr, int n)
{
    int count = 0;

    for(int i = n / 2; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 0)
            {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;

    cout << "Please, input n =";
    cin >> n;
    cout << endl;

    if(n <= 0)
    {
        cout << "Please, input correct array size!" << endl;
        return 0;
    }

    // Создание динамического двумерного массива
    int** arr = new int*[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    srand(time(nullptr));

    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 62 - 31; // заполняем ячейку случайным числом от -31 до 31
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " "; // выводим
        }
        cout << endl;
    }

    cout << endl << "Count Zeros In Lower Half = " << countZerosInLowerHalf(arr, n) << endl;

    cout << endl;
    replaceUpperHalfWithMin(arr, n);

    return 0;
}