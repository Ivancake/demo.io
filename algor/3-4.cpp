#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, S = 4;
    cin >> n;
    int M = pow(2, n) - 1;
    if (n == 1)
    {
        cout << "Число: " << M << " не простое" << endl;
        return 0;
    }
    if (n == 2)
    {
        cout << "Число:" << M << " простое" << endl;
        return 0;
    }
    for(int i = 0; i < n - 2; ++i){
        S = (S * S - 2) % M;
    }
    if (S == 0)
        cout << "Число: " << M << " простое" << endl;
    else
        cout << "Число: " << M << " не простое" << endl;
    return 0;
}