#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// функция для проверки простое число или нет
int prost(int n, int *numbers, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (numbers[i] == n)
            return 1;
    }
    return 0;
}
int main()
{
    int num, count = 0;
    cin >> num;
    int *deliteli = new int[num]; // массив для простых делителей
    int *crat = new int[num]; // массив для кратности множителей
    int *numbers = new int[num]; // массив для решета Эратосфена
    // реализация алгоритма решета Эратосфена
    int numbers_count = 0;
    for (int i = 2; i <= num; ++i)
    {
        numbers[i - 2] = i;
        numbers_count++;
    }
    int cur_ind = 0;
    int cur_num = 0;
    while (cur_ind < numbers_count)
    {
        if (numbers[cur_ind] != 0)
        {
            cur_num = numbers[cur_ind];
            for (int i = cur_ind + 1; i < numbers_count; ++i)
            {
                if (numbers[i] != 0 && numbers[i] % cur_num == 0)
                    numbers[i] = 0;
            }
        }
        cur_ind++;
    }
    int or_num = num; // сохраняем исходное число
    // перебираем все делители числа
    for (int i = 2; i <= or_num; ++i)
    {
        int pr = prost(i, numbers, numbers_count);
        if (num % i == 0 && pr == 1)
        {
            deliteli[count] = i;
            crat[count] = 0;
            while (num % i == 0)
            {
                crat[count]++;
                num /= i;
            }
            count++;
        }
    }
    for (int i = 0; i < count; ++i)
    {
        cout << "Множитель: " <<deliteli[i] << ' ' << "кратность: " <<crat[i] << endl;
    }
    delete[] deliteli;
    delete[] crat;
    delete[] numbers;
    return 0;
}