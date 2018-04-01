#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<vector<int>> table;
int main() {
	scanf("%d %d", &n, &m);
	table.resize(n, vector<int>(m));
	int tmep;
	for (int tmp, i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &tmp);
			table[i][j] = 1 << tmp;
		}
	}
	int maxLen = min(n, m);
	maxLen--;
	bool find;
	int len = 1;
	for (int k = 1; k <= maxLen; k++) {
		for (int i = 0; i < n-k; i++) {
			for (int j = 0; j < m - k; j++) {
				find = false;
				if ((table[i][j] & table[i + k][j] & table[i][j + k] & table[i + k][j + k]) == table[i][j]) {
					find = true;
					len = k+1;
				}
			}
			if (find)
				break;
		}
	}
	printf("%d", len*len);
	return 0;
}