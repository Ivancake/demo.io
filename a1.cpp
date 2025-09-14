#include <iostream>
#include <cmath>
using namespace std;
// 1 variant
int main()
{
    double a = 0, b = 1, p = pow(exp(1), a - 1) - pow(a, 3) - a, q = pow(exp(b), b - 1) - pow(b, 3) - b, tempx, tempy, e = 0.00001;
    while (abs(q) > e)
    {
        tempx = b - q * (b - a) / (q - p);
        tempy = pow(exp(1), tempx - 1) - pow(tempx, 3) - tempx;
        a = b;
        p = q;
        b = tempx;
        q = tempy;

        cout << tempx << 'b' << endl;
    }
    return 0;
}
// 8 variant
/*int main()
{
    double a = 1, b = 2, p = 0.1 * pow(a, 2) - a * log(a), q = 0.1 * pow(b, 2) - b * log(b), tempx, tempy, e = 0.00001;
    while (abs(q) > e)
    {
        tempx = b - q * (b - a) / (q - p);
        tempy = 0.1 * pow(tempx, 2) - tempx * log(tempx);
        a = b;
        p = q;
        b = tempx;
        q = tempy;
        cout << tempx << endl;
    }
    return 0;
}*/