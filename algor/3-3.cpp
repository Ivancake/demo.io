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
        if (numbers[i] > n)
            break;
    }
    return 0;
}
// метод ферма
pair<int, int> ferma(int n)
{
    int a = ceil(sqrt(n));
    double b2, b;

    for (int i = 0; i < 10000; i++)
    {
        b2 = (double)a * a - n;
        b = sqrt(b2);
        if (b * b == b2)
        {
            return make_pair(a - b, a + b); // возвращаем разложение
        }
        a++;
    }
    return make_pair(1, n); // если не нашли разложение
}

// функция для нахождения простых делителей числа и их кратность
void prost_deliteli(int *deli, int *cr, int &count, int n, int *numbers, int size)
{
    for (int i = 0; i < size && numbers[i] <= n; ++i)
    {
        if (numbers[i] == 0)
            continue;
        if (n % numbers[i] == 0)
        {
            deli[count] = numbers[i];
            cr[count] = 0;
            while (n % numbers[i] == 0)
            {
                cr[count]++;
                n /= numbers[i];
            }
            count++;
        }
    }
}
int main()
{
    int num, count = 0;
    cin >> num;
    double m = sqrt(num);
    int *deliteli = new int[num]; // массив для простых делителей
    int *crat = new int[num];     // массив для кратности множителей
    int *numbers = new int[num];  // массив для решета Эратосфена
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
    // Применяем метод Ферма для нахождения двух делителей
    pair<int, int> res = ferma(num);
    // оба делители простые
    if (prost(res.first, numbers, numbers_count) == 1 && prost(res.second, numbers, numbers_count) == 1)
    {
        deliteli[0] = res.first;
        crat[0] = 1;
        deliteli[1] = res.second;
        crat[1] = 1;
        count = 2;
    }
    else
    {
        // первый делитель не простой
        if (prost(res.first, numbers, numbers_count) == 0)
        {
            prost_deliteli(deliteli, crat, count, res.first, numbers, numbers_count);
        }
        // первый делитель простой
        else
        {
            deliteli[count] = res.first;
            crat[count] = 1;
            count++;
        }
        // второй делитель не простой
        if (prost(res.second, numbers, numbers_count) == 0)
        {
            prost_deliteli(deliteli, crat, count, res.second, numbers, numbers_count);
        }
        // второй делитель простой
        else
        {
            deliteli[count] = res.second;
            crat[count] = 1;
            count++;
        }
    }
    // объединяем одинаковые множители
    for (int i = 0; i < count; ++i)
    {
        for (int j = i + 1; j < count; ++j)
        {
            if (deliteli[i] == deliteli[j] && deliteli[i] != 0)
            {
                crat[i] += crat[j];
                deliteli[j] = 0;
                crat[j] = 0;
            }
        }
    }
    for (int i = 0; i < count; ++i)
    {
        if (deliteli[i] != 0 && crat[i] != 0) // добавляем проверку на ненулевую кратность
        {
            cout << "Множитель: " << deliteli[i] << ' ' << "кратность: " << crat[i] << endl;
        }
    }
    delete[] deliteli;
    delete[] crat;
    delete[] numbers;
    return 0;
}
