#include<iostream>
#include<vector>
using namespace std;
int t, n;
vector<bool> check;
vector<int> p;

int find(int pos, int cnt) {
	if (pos == n - 1)
		return cnt;
	if (p[pos] == -1||check[pos]==true)
		return 0;
	check[pos] = true;
	return find(p[pos], cnt + 1);
}

int main() {
	scanf("%d", &t);
	bool jd;
	while (t--) {
		jd = false;
		scanf("%d", &n);
		check.clear();
		check.resize(n, false);
		p.resize(n, -1);
		for (int temp, i = 0; i < n; i++) {
			scanf("%d", &temp), p[i] = (temp - 1);
			if (temp == n - 1)jd = true;
		}
		if (!jd) {
			printf("%d\n", 0);
			continue;
		}
		printf("%d\n", find(0, 0));
	}
	return 0;
}