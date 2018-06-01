#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, x;
vector<int> s, c;
bool check(int cnt) {
	bool ret = true;
	int money= x;
	for (int i = 0; i < cnt; i++) {
		int tmp = c[i] - s[s.size()-(cnt-i)];
		if (tmp > 0)
			if (money >= tmp)
				money -= tmp;
			else return false;

	}
	return true;
}
int main() {
	scanf("%d %d %d", &n, &m, &x);
	c.resize(n), s.resize(m);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &s[i]);
	sort(c.begin(), c.end());
	sort(s.begin(), s.end());
	int l = 0;
	int r = min(n,m);
	int mid;
	while (l < r) {
		mid = (l + r + 1) >> 1;
		if (check(mid))
			l = mid;
		else
			r = mid-1;
	}
	printf("%d", l);

	return 0;
}