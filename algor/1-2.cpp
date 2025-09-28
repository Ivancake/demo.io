#include <iostream>
#include <cmath>
using namespace std;
// 8 variant
int main()
{
    double a = 1, b = 2, p = 0.1 * pow(a, 2) - a * log(a), q = 0.1 * pow(b, 2) - b * log(b), tempx, tempy, e = 0.00001;
    while (abs(b - a) > e)
    {
        tempx = a - p * (b - a) / (q - p); // находим точку пересечение хорды с осью x по формуле
        tempy = 0.1 * pow(tempx, 2) - tempx * log(tempx); // находим значение этой точки
        // присваиванием точке a значение b, а точке b новое значение, которое нашли по формуле
        a = b;
        p = q;
        b = tempx;
        q = tempy;
        cout << tempx << endl;
    }
    return 0;
}