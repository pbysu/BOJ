#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> p;
vector<p> v;
int main() {
	int n;
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d %d", &v[i].first, &v[i].second);
	sort(v.begin(), v.end(), [](p &a, p &b) {
		if (a.second != b.second)
			return a.second < b.second;
		else
			return a.first < b.first;
	});
	int ans = 0;
	for (int e=-1, i = 0; i < v.size(); i++) {
		if (v[i].first >= e) {
			e = v[i].second;
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}