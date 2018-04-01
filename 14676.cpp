#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> cnt;
vector<vector<int>>adj;
vector<vector<int>> rev;
int n, m, k, u, v, t;
bool answer;
int main() {
	scanf("%d %d %d", &n, &m, &k);
	rev.resize(n + 1);
	cnt.resize(n + 1);
	answer = true;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		rev[v].push_back(u);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &t, &u);
		bool jd = false;
		if (t == 1) {
			if (rev[u].size() == 0) {
				jd = true;
			}
			else {
				for (auto next : rev[u]) {
					if (cnt[next] != 0) {
						jd = true;
						break;
					}
				}
			}
			if (jd) cnt[u]++;
			else {
				answer = false;
			}
		}
		else if (t == 2) {
			if (--cnt[u] < 0) answer = false;
		}
	}
	if (answer)
		printf("King-God-Emperor");
	else
		printf("Lier!");

	return 0;
}