#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t, n;
vector<int> v;
vector<int> pre;
int ans;
int main() {
	scanf("%d", &t);
	while (t--) {
		pre.clear();
		v.clear();
		scanf("%d", &n);
		v.resize(n+1);
		pre.resize(n+1);
		ans = -1091309;
		pre[0] = 0;

		for (int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
			pre[i] = v[i] + pre[i - 1];
		}
		for (int i = 1; i <= n; i++) 
			for (int j = i-1; j >=0;j--) 
				ans = max(ans, pre[i] - pre[j]);
		printf("%d\n", ans);
	}
	return 0;
}