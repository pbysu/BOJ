#include<iostream>
#include<vector>
#include<set>


using namespace std;
set<int> s;
int n, m, t;
vector<int>p;
vector<int> deep;

int find(int q) {
	if (q == p[q])
		return q;
	return p[q] = find(p[q]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (deep[a] > deep[b])
		swap(a, b);
	p[b] = a;
	deep[a]++;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		p.resize(n);
		deep.resize(n, 0);

		for (int i = 0; i < n; i++)
			p[i] = i;

		for (int temp, i = 0; i < n; i++) {
			scanf("%d", &temp);
			merge(i, temp-1);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] == i)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}