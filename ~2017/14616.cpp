#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, m;
ll p, q, x, y;
pair<pair<ll,ll>,pair<ll,ll>> node[100001];
pair<ll, ll > raz[100001];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld %lld", &p, &q, &x, &y);
		if (q*x < p*y) node[i] = { { p,q },{ x,y } };
		else node[i] = { { x,y },{ p,q } };
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) 
		scanf("%lld %lld", &raz[i].first, &raz[i].second);
	sort(raz, raz + m, [](pair<ll, ll> a, pair<ll, ll> b)
	{
		return b.first*a.second < b.second*a.first;
	});

	int ret = 0;

	for (int i = 0; i < n; i++) {
		int l = 0, r = m - 1, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (raz[mid].first * node[i].first.second <= node[i].first.first * raz[mid].second
				&& raz[mid].first*node[i].second.second >= raz[mid].second * node[i].second.first) {
				ret++;
				break;
			}
			else if(raz[mid].first * node[i].first.second > node[i].first.first * raz[mid].second)
				l = mid + 1;
			else
				r = mid - 1;
		}
	}
	printf("%d\n", n-ret);
	return 0;
}