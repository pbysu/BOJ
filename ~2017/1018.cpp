#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;
int n, m;
vector<vector<char>> table;
int main() {
	scanf("%d %d", &n, &m);
	table.resize(n, vector<char>(m));
	getchar();
	for (int c, i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &table[i][j]);
		}
		getchar();
	}


	int cnt = 0;
	int minCnt = INF;
	bool stop = false;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			cnt = 0;
			for (int p = 0; p < 8; p++) {
				for (int q = 0; q < 8; q++) {
					if ((i + j + q + p) % 2 == 0) {
						if (table[i + p][j + q] == 'W') cnt++;
					}
					else if (table[i + p][j + q] == 'B')cnt++;
				}

			}
			if (cnt > 32) cnt = 64 - cnt;
			minCnt = min(cnt,minCnt);
		}
	}
	printf("%d", minCnt);
	return  0;
}