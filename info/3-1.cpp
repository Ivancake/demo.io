#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// 1
/*int main()
{
    srand(time(0));
    int a, midl = 0;
    cin >> a;
    int* arr = new int[a];
    for (int i = 0; i < a; i++) {
        arr[i] = rand() % 201 - 100; // от -100 до 100
        midl += arr[i];
        if (i == a - 1)
            cout << arr[i] << endl;
        else
            cout << arr[i] << ' ';
    }
    cout << midl / (double)a << endl;
    delete[] arr;
    return 0;
}*/
// 2
/*int main()
{
    srand(time(0));
    int a, cnt_ch = 0, cnt_nch = 0;
    cin >> a;
    int* arr = new int[a];
    for (int i = 0; i < a; i++) {
        arr[i] = rand() % 201 - 100; // от -100 до 100
        if (arr[i] % 2 == 0)
            cnt_ch += 1;
        else
            cnt_nch += 1;
        if (i == a - 1)
            cout << arr[i] << endl;
        else
            cout << arr[i] << ' ';
    }
    cout << cnt_ch << ' ' << cnt_nch << endl;
    delete[] arr;
    return 0;
}*/
// 3
/*int main()
{
    srand(time(0));
    int a, maxx = 0, minn = 0;
    cin >> a;
    int* arr = new int[a];
    for (int i = 0; i < a; i++) {
        arr[i] = rand() % 201 - 100; // от -100 до 100
        if (arr[i] > maxx)
            maxx = arr[i];
        if (arr[i] < minn)
            minn = arr[i];
        if (i == a - 1)
            cout << arr[i] << endl;
        else
            cout << arr[i] << ' ';
    }
    cout << maxx << ' ' << minn << endl;
    delete[] arr;
    return 0;
}*/
// 4
/*int main() {
    srand(time(0));
    int n, m;
    cin >> n >> m;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % 201 - 100;
            if (j == m - 1)
                cout << arr[i][j] << endl;
            else
                cout << arr[i][j] << ' ';
        }
    }
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}*/
// 5
/*int main() {
    srand(time(0));
    int n, m, summ = 0;
    cin >> n >> m;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m]; 
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % 201 - 100;
            summ += arr[i][j];
            if (j == m - 1)
                cout << arr[i][j] << endl;
            else
                cout << arr[i][j] << ' ';
        }
    }
    cout << summ << endl;
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}*/
// 6
int main() {
    srand(time(0));
    int n, m, summ = 0;
    cin >> n >> m;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % 201 - 100;
            if (i == j)
                summ += arr[i][j];
            if (j == m - 1)
                cout << arr[i][j] << endl;
            else
                cout << arr[i][j] << ' ';
        }
    }
    cout << summ << endl;
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}