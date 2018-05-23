#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;

using namespace std;
ll n, m, k;

vector<ll> seg;
vector<ll>lazy;


void lazyUpdate(ll node, ll x, ll y) {
	if (!lazy[node])return;
	seg[node] += (y - x + 1)*lazy[node];
	if (x != y) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

ll update(ll lo, ll hi, ll val,ll node, ll x, ll y) {
	lazyUpdate(node, x, y);

	if (y < lo || hi < x)
		return seg[node];

	if (lo <= x && y <= hi) {
		lazy[node] += val;
		lazyUpdate(node, x, y);
		return seg[node];
	}

	ll mid = (x + y) >> 1;

	ll left = update(lo, hi,val, node * 2, x, mid);
	ll right = update(lo, hi,val, node * 2 + 1, mid + 1, y);

	return seg[node] = left + right;
}
ll query(ll lo, ll hi, ll node, ll x, ll y) {
	lazyUpdate(node, x, y);
	if (y < lo || hi < x)
		return 0;
	if (lo <= x&&y <= hi)
		return seg[node];
	ll mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}


int main() {
	ll tmp;
	ll a, b, c;
	scanf("%lld %lld %lld", &n, &m, &k);
	seg.resize((n + 1) * 4);
	lazy.resize((n + 1) * 4);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &tmp);
		update(i, i, tmp, 1, 0, n - 1);
	}

	for (ll i = 0; i < m + k; i++) {
		scanf("%lld", &a);

		if (a == 1) {
			scanf("%lld %lld %lld", &b, &c, &tmp);
			update(b - 1, c - 1, tmp, 1, 0, n - 1);
		}
		else {
			scanf("%lld %lld", &a, &b);
			printf("%lld\n", query(a - 1, b - 1, 1, 0, n - 1));
		}
	}

	return 0;
}