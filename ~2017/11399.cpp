#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, tmp;
vector<int> v;
int main() {
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {
		v[i] += v[i - 1];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += v[i];
	}
	printf("%d", ans);
	return 0;
}