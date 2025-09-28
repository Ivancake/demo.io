#include<iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
struct Friend
{
    string surname;
    string name;
    int score1;
    int score2;
    int score3;
};

int main(){
    int n;
    cin >> n;
    double sum1 = 0, sum2 = 0, sum3 = 0;
    vector<Friend> friends(n);
    for(int i = 0; i < n; ++i){
        cin >> friends[i].surname
            >> friends[i].name
            >> friends[i].score1
            >> friends[i].score2
            >> friends[i].score3;
    sum1 += friends[i].score1;
    sum2 += friends[i].score2;
    sum3 += friends[i].score3;
    }
    cout << fixed << setprecision(1);
    cout << sum1 / n << ' ' << sum2 / n << ' ' << sum3 / n << endl;
    return 0;
}