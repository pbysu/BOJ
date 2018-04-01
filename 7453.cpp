#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;
typedef long long ll;
vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
vector<int> cd;

int main() {
	int n;
	int at, bt, ct, dt;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &at, &bt, &ct, &dt);
		a.push_back(at);
		b.push_back(bt);
		c.push_back(ct);
		d.push_back(dt);
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			cd.push_back(c[i] + d[j]);
		}
	}

	sort(cd.begin(), cd.end());
	ll ans = 0;
	int t;
	for (int k = n - 1; k >= 0; k--) {
		for (int j = n - 1; j >= 0; j--) {
			t = (a[k] + b[j])*-1;
			ans += upper_bound(cd.begin(), cd.end(), t) - lower_bound(cd.begin(), cd.end(), t);
		}
	}
	printf("%lld", ans);

	return 0;
}