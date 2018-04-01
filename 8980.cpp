#include<vector>
#include<algorithm>
using namespace std;
int n, k, m;
typedef long long ll;
vector<pair<pair<int, int>, ll>> node;
typedef pair<pair<int, int>, ll> pp;
vector<ll> his;
int main() {
	scanf("%d %d", &n, &k);
	his.resize(n + 1);
	scanf("%d", &m);
	node.resize(m);
	for (int s, e, c, i = 0; i < m; i++) {
		scanf("%d %d %lld", &node[i].first.first, &node[i].first.second, &node[i].second);
	}
	sort(node.begin(), node.end(), [](pp a, pp b) {
		if (a.first.first != b.first.first)
			return a.first.first < b.first.first;
		else
			return a.first.second < b.first.second;
	});
	int ex = 1;
	int pos;
	ll ans = 0;
	ll total = 0;
	int r = 0;

	for (int b = 1; b <= n; b++) {
		ans += his[b];
		total -= his[b];
		his[b] = 0;
		for (r; r < m; r++) {
			pos = node[r].first.first;
			int e = node[r].first.second;
			ll cost = node[r].second;

			if (b != pos) {
				break;
			}
			if (total + cost <= k) {
				his[e] += cost;
				total += cost;
			}
			else {
				ll x = k - total;
				his[e] += x;
				total = k;
				x = cost - x;
				for (int j = n; j > e; j--) {
					if (his[j] >= x) {
						his[j] -= x;
						his[e] += x;
						break;
					}
					else {
						his[e] += his[j];
						x -= his[j];
						his[j] = 0;
					}
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}