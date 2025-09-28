#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
// 1
/*int main() {
	srand(time(0));
	int n;
	cin >> n;
	vector<int> data;
	for(int i = 0; i != n; ++i) {
		data.push_back(rand() % 10 + 0);
		cout << data[i] << ' ';
	}
	cout << "\n";
	int count = 0, i = 0;
	while(i < data.size() - 1) {
		if(data[i] == data[i + 1]) {
			count += 2;
			data.erase(data.begin() + i, data.begin() + i + 2);
			i = max(0, i - 1);
		}
		else
			i++;
	}
	cout << count << endl;
	return 0;
}*/
// 2
/*int main(){
	size_t n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	for(size_t i = 0; i != n; ++i){
		for(size_t j = 0; j != n; ++j){
			if(i + j < n - 1)
				matrix[i][j] = 0;
			else if(i + j == n - 1)
				matrix[i][j] = 1;
			else if(i + j > n - 1)
				matrix[i][j] = 2;
		}
	}
	for(size_t i = 0; i != n; ++i)
	{
		for(size_t j = 0; j != n; ++j)
		{
			if(j == n - 1)
				cout << matrix[i][j] << endl;
			else
				cout << matrix[i][j] << ' ';
		}
	}
	return 0;
}*/
// 3
int main(){
	int n, m, w;
	cin >> n >> m >> w;
	vector<vector<char>> matrix(n, vector<char>(m, '0'));
	for(int i = 0, j = 0, k = 0; k < w; ++k){
		cin >> i >> j;
		matrix[i - 1][j - 1] = '*';
	}
	for(size_t i = 0; i != n; ++i){
		for(size_t j = 0; j != m; ++j){
			int count = 0;
			if(matrix[i][j] != '*'){
				for (int i1 = -1; i1 <= 1; ++i1)
				{
					for (int j1 = -1; j1 <= 1; ++j1)
					{
						if (j1 == 0 && i1 == 0) // сама ячейка
							continue;
						if (j + j1 >= 0 && j + j1 < m && i + i1 >= 0 && i + i1 < n)
						{
							if (matrix[i + i1][j + j1] == '*')
								count += 1;
						}
					}
				}
				matrix[i][j] = '0' + count;
			}
		}
	}
	for(size_t i = 0; i != n; ++i){
		for(size_t j = 0; j != m; ++j){
			if(j == m - 1)
				cout << matrix[i][j] << endl;
			else
				cout << matrix[i][j] << ' ';
		}
	}
	return 0;
}
