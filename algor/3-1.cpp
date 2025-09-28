#include <iostream>
using namespace std;
// 1 nechet
int nod(int a, int b) {
 while (b != 0) {
  int c = b;
  b = a % b;
  a = c;
 }
 return a;
}
int main() {
 int num1, num2, num3;
 cin >> num1 >> num2 >> num3;
 int nod12 = nod(num1, num2);
 int nod123 = nod(nod12, num3);
 cout << nod123 << endl;
 return 0;
}