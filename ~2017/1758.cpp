#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int n;
vector<int> in;
int main() {
	scanf("%d", &n);
	in.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	long long ans = 0;
	sort(in.begin(), in.end(), [](int p, int q) {return p > q; });
	for (int i = 0; i < n; i++) {
		if (in[i]- i <= 0)break;
		ans += in[i] - i;
	}

	printf("%lld", ans);
	return 0;
}