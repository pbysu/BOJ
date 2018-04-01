#include<iostream>
#include<vector>

using namespace std;

vector<bool> visited;
vector<int> check;
struct Edge {
	int to, cnt;
	Edge *dual;
	Edge() : Edge(-1, 0) {}
	Edge(int to1, int cnt1) : to(to1), cnt(cnt1), dual(nullptr){}
};

vector<vector<Edge*>> edge;

int dfs(int pos) {
	int ret = 1;
	visited[pos] = true;
	for (Edge* e : edge[pos]) {
		int next = e->to;
		if (!visited[next])ret += dfs(next);
	}
	return ret;
}

void Eulerian(int pos) {
	for (Edge *e : edge[pos]) {
		if (e->cnt > 0) {
			e->cnt--;
			e->dual->cnt--;

			Eulerian(e->to);
		};
	}
	printf("%d ", pos+1);
}


int main() {
	int n, temp;
	scanf("%d", &n);

	visited.resize(n);
	check.resize(n);
	edge.resize(n);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &temp);
			if (j > i && temp>0) {
				Edge *e1 = new Edge(j, temp);
				Edge *e2 = new Edge(i, temp);
				e1->dual = e2;
				e2->dual = e1;
				edge[i].push_back(e1);
				edge[j].push_back(e2);
				check[i] += temp;
				check[j] += temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (check[i] % 2) {
			printf("-1");
			return 0;
		}
	}

	bool flag = false;
	int start = -1;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			int size = dfs(i);
			if (size > 1) {
				if (flag) {
					printf("-1");
					return 0;
				}
				else {
					start = i;
					flag = true;
				}

			}
		}
	}
	if (start == -1) start = 0;
	Eulerian(start);

	return 0;
}