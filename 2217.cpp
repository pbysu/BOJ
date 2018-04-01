#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

vector<int> v;
int main() {
	int n;
	scanf("%d", &n);
	v.resize(n);
	int s = 10001;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end(),greater<int>());
	int ans = 0;
	for (int i = 0; i < v.size(); i++)ans = max(ans, (i + 1)*v[i]);
	printf("%d", ans);
}