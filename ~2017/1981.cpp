#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int input[100][100];
bool visited[101][101];
int ans;
int n;
int Max = 0;
int Min = 987654321;

int dr[] = { 0, 0, -1, 1 };
int dc[] = { 1, -1, 0, 0 };



bool bfs(int lo, int hi) {
	int tc, tr, ttr, ttc;
	queue<pair<int, int>> q;
	pair<int, int> temp;

	if (input[0][0]< lo || input[0][0]>hi) 
		return false;

	q.push({ 0,0 });
	visited[0][0] = true;

	int sizeq;

	while (!q.empty()) {

		sizeq = q.size();


		for (int k = 0; k < sizeq; k++) {
			temp = q.front();
			q.pop();
			tr = temp.first;
			tc = temp.second;


			for (int i = 0; i < 4; i++) {
				ttr = tr + dr[i];
				ttc = tc + dc[i];

				if (ttr < 0 || ttr >= n || ttc < 0 || ttc >= n)
					continue;

				if (visited[ttr][ttc] || input[ttr][ttc]>hi || input[ttr][ttc] < lo)
					continue;

				visited[ttr][ttc] = true;

				q.push({ ttr, ttc });

				if (visited[n - 1][n - 1])
					return true;

			}
		}

	}

	return false;
}

void func(int x, int y) {
	
	if (x == y) {
		int mid = x;
		bool jd = false;

		for (int i = 0; i <= Max - mid; i++) {
			memset(visited, false, sizeof(visited));
			if (bfs(i, i + mid)) {
				jd = true;
				break;
			}
		}
		if (jd) {
			ans = x;
		}
		else
			ans = x + 1;

		return;
	}

	int mid = (x + y) >> 1;
	bool jd = false;
	for (int i = 0; i <= Max - mid; i++) {
		memset(visited, false, sizeof(visited));
		if (bfs(i, i + mid)) {
			jd = true;

			break;
		}
	}

	if (jd)
		return func(x, mid);

	else {
		return func(mid + 1, y);
	}

}




int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &input[i][j]);
			Max = max(Max, input[i][j]);
		}
	}

	func(0, Max);
	printf("%d", ans);
	return 0;
}