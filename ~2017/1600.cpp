#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int k, m, n;
int table[200][200];
bool check[200][200][30];
int dr[12] = { 0,0,1,-1, 2,2,  1,1, -1,-1, -2,-2 };
int dc[12] = { 1,-1,0,0, 1,-1, 2,-2, 2,-2, 1,-1 };

int func(int r, int c, int jmp) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},0 });
	bool jd = false;
	int w = 0;
	while (!q.empty()) {
		if (jd)break;
		w++;
		int siz = q.size();
		for (int i = 0; i < siz; i++) {
			int tr = q.front().first.first;
			int tc = q.front().first.second;
			if (tr == n - 1 && tc == m - 1) {
				jd = true;
				break;
			}
			int jm = q.front().second;
			q.pop();

			if (jm < k) {
				for (int j = 0; j < 12; j++) {
					int ttr = tr + dr[j];
					int ttc = tc + dc[j];
					
						if (ttr >= 0 && ttr < n && ttc >= 0 && ttc < m) {
							if (j >= 4) {
								if(!check[ttr][ttc][jm + 1] && table[ttr][ttc] != 1)check[ttr][ttc][jm + 1] = true, q.push({ { ttr,ttc },jm + 1 });
							}
							else {
								if(!check[ttr][ttc][jm] && table[ttr][ttc] != 1)check[ttr][ttc][jm] = true, q.push({ { ttr,ttc },jm });
							}

						}
				}
			}
			else {
				for (int j = 0; j < 4; j++) {
					int ttr = tr + dr[j];
					int ttc = tc + dc[j];
					if (ttr >= 0 && ttr < n && ttc >= 0 && ttc < m) {
						if(!check[ttr][ttc][jm] && table[ttr][ttc] != 1) check[ttr][ttc][jm] = true, q.push({ { ttr,ttc },jm });
					}
				}
			}
		}
	}
	if (jd)
		return w-1;
	else
		return -1;
}

int main() {
	scanf("%d", &k);
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &table[i][j]);
		}
	}

	printf("%d", func(0, 0, 0));

	return 0;
}