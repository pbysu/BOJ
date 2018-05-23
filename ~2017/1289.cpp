#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;
typedef long long ll;
int n;
vector<vector<pair<int,int>>> adj;
bool check[100001];
ll ret;
ll func(int pos , int ex) {
	ll s = 1, t;
	for (pair<int,int> next : adj[pos]) {
		if (next.first != ex) {
			t = func(next.first, pos)* next.second%mod;
			ret = (ret + t*s) % mod;
			s = (s + t) % mod;
		}
	}
	return s;
}

int main() {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int u ,v,c, i = 1; i < n; i++) {
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}
	func(1, 0);
	printf("%d",ret );


	return 0;
}