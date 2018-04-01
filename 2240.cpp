#include<iostream>
#include<algorithm>
#include<cstring>

#define INF 987654321
using namespace std;

int pos[2][1010][31];

int main() {

	int t, w;
	memset(pos, -1, sizeof(pos));

	scanf("%d %d", &t, &w);
	int tmp;
	scanf("%d", &tmp);
	pos[0][1][0] = 0; pos[1][1][0] = 0;
	pos[tmp - 1][1][0] = 1;


	for (int i = 2; i <= t; i++) {
		scanf("%d", &tmp);
		for (int j = 0; j <= w; j++) {
			if (tmp == 1) {
				if (pos[0][i - 1][j] != -1)
					pos[0][i][j] = max(pos[0][i - 1][j] + 1, pos[0][i][j]);

				if (pos[1][i - 1][j - 1] != -1 && j - 1 >= 0)
					pos[0][i][j] = max(pos[0][i][j], pos[1][i - 1][j - 1] + 1);

				if (pos[0][i - 1][j - 1] && j > 0) pos[1][i][j] = max(pos[1][i][j], pos[0][i - 1][j - 1]);

				if (pos[1][i - 1][j] != -1)	pos[1][i][j] = max(pos[1][i][j], pos[1][i - 1][j]);

			}

			else {
				if (pos[1][i - 1][j] != -1)
					pos[1][i][j] = max(pos[1][i][j], pos[1][i - 1][j] + 1);

				if (pos[0][i - 1][j - 1] != -1 && j - 1 >= 0)
					pos[1][i][j] = max(pos[1][i][j], pos[0][i - 1][j - 1] + 1);

				if (pos[1][i - 1][j - 1] && j > 0)pos[0][i][j] = max(pos[1][i - 1][j - 1], pos[0][i][j]);
				if (pos[0][i - 1][j] != -1)	pos[0][i][j] = max(pos[0][i][j], pos[0][i - 1][j]);

			}
		}
	}


	int ans = -1;
	for (int i = 0; i <= w; i++) {
		ans = max(pos[0][t][i], ans);
		ans = max(pos[1][t][i], ans);
	}

	printf("%d", ans);
	return 0;
}