#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

queue<int> q;
bool visited[1000001];
int f, g, s, u, d;


int bfs(int s) {
	q.push(s);
	int temp;
	int ans = 0;
	int sizeq = q.size();
	int ups, dos;

	while (!q.empty()) {
		sizeq = q.size();
		ans++;

		while (sizeq--) {
			temp = q.front();
			q.pop();

			ups = temp + u;
			dos = temp - d;

			if (dos == g || ups == g)
				return ans;

			visited[temp] = true;
			if (ups <= f &&!visited[ups]) {
				q.push(ups);
				visited[ups] = true;
			}
				
			if (dos >= 1 &&!visited[dos] ) {
				q.push(dos);
				visited[dos] = true;
			}
				

		}
	}

	printf("use the stairs\n");
	return -1;
}

int main() {

	scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
	if (s == g) printf("0\n");

	else {
		int ans = bfs(s);

		if (ans != -1)
			printf("%d", ans);
	}
	

	return 0;
}