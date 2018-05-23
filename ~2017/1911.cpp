#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	sort(v.begin(), v.end());
	int s = 0;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		s = max(v[i].first, s);
		ret += (v[i].second - s + m - 1) / m;
		s += ((v[i].second - s + m - 1)/m)*m;
	}
	printf("%d", ret);
}