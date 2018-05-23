#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int> v;
int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);

	}

	sort(v.begin()+1, v.end(), [](int p, int q) {return p > q; });
	for (int i = 1; i <= n; i++) {
		v[i] = v[i] + i+1;
		ret = max(v[i], ret);
	}
	printf("%d", ret);

	return 0;
}