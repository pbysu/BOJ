#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int input[101][101];
int visited[101][101];

pair<int, int> d[4];


int bfs(pair<int, int> s) {

	queue<pair<int, int>> q;
	q.push(s);
	visited[s.first][s.second] = true;
	int ret = 1;
	int sizeq;
	while (!q.empty()) {

		sizeq = q.size();

		for (int i = 0; i < sizeq; i++) {
			


			for (int i = 0; i < 4; i++) {

				pair<int, int> temp = { q.front().first + d[i].first, q.front().second + d[i].second };
				if (temp.first == n && temp.second == m)
					return ret + 1;

				if (temp.first > n || temp.second > m) continue;

				if (!visited[temp.first][temp.second] &&
					input[temp.first][temp.second] == 1) {

					q.push(temp);
					visited[temp.first][temp.second] = ret;

				}

			}
			q.pop();
		}

		ret++;
	}

	return ret;

}
int main() {
	d[0] = { 1,0 };
	d[1] = { -1,0 };
	d[2] = { 0, 1 };
	d[3] = { 0,-1 };

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &input[i][j]);
		}
	}

	printf("%d", bfs({ 1,1 }));


	return 0;
}