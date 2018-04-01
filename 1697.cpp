#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 100000
using namespace std;

queue<int> q;
int s, g;
bool visited[100001];


int bfs(int s) {
	q.push(s);
	int temp;
	int ans = 0;
	int sizeq = q.size();
	int ups;
	int dos;
	int muls;

	while (!q.empty()) {
		sizeq = q.size();
		ans++;

		while (sizeq--) {
			temp = q.front();
			q.pop();

			ups = temp + 1;
			dos = temp - 1;
			muls = temp * 2;

			if (g == dos || ups == g || muls == g)
				return ans;

			visited[temp] = true;

			if (muls <= INF && !visited[muls]) {
				q.push(muls);
				visited[muls] = true;
			}
			if (ups <= INF &&!visited[ups]) {
				q.push(ups);
				visited[ups] = true;
			}

			if (dos >= 1 && !visited[dos]) {
				q.push(dos);
				visited[dos] = true;
			}


		}
	}
}

	int main() {

		scanf("%d%d", &s, &g);
		if (s == g) printf("0");
		else 
		printf("%d", bfs(s));
		return 0;
	}