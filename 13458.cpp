#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, tmp, b, c;
typedef long long ll;
vector<int> v;
int main() {
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	scanf("%d %d", &b,&c);
	ll cnt = 0;

	for (int i = 0; i < n; i++) {
		ll tmp = v[i] - b;
		if (tmp > 0) {
			cnt += (tmp) / c;
			if ((v[i] - b) % c != 0)
				cnt++;
		}

	}
	printf("%lld", cnt+(ll)n);
	return 0;


}