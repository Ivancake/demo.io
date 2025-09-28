#include <iostream>
#include <cmath>
using namespace std;
// 8 variant
int main()
{
    double a = 1, b = 2, p = 0.1 * pow(a, 2) - a * log(a), q = 0.1 * pow(b, 2) - b * log(b), tempx, tempy, e = 0.00001;
    while (abs(b - a) > e)
    {
        tempx = (a + b) / 2;                              // делим отрезок пополам
        tempy = 0.1 * pow(tempx, 2) - tempx * log(tempx); // находим значение этой точки
        if (tempy * q < 0)                                // корень в правой половине
        {
            p = tempy;
            a = tempx;
        }
        else // корень в левой половине
        {
            q = tempy;
            b = tempx;
        }
        cout << tempx << endl;
    }
    return 0;
}
