#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;
queue<pii> q;
vector<int> fuel;
int n, k;
int fuelFunction(int p, int q) {
	double len = sqrt((pow(v[p].first - v[q].first, 2) + pow(v[p].second - v[q].second, 2)));
	int tmp = ceil(len);

	int ret = tmp / 10;
	if (tmp % 10 != 0)ret += 1;
	return ret;
}
int main() {
	scanf("%d %d", &n, &k);
	v.resize(n+2);
	fuel.resize(n+2, INF);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	v[0] = { 0,0 };
	v[n + 1] = { 10000,10000 };
	fuel[0] = 0;
	q.push({ 0,0 });
	int cnt = -1;
	while (!q.empty()) {
		int siz = q.size();
		if (cnt == k)
			break;
		cnt++;
		for (int i = 0; i < siz; i++) {
			for (int i = 1; i <= n+1; i++) {
				int f = max( q.front().second,fuelFunction(q.front().first, i));
				if (f < fuel[i]) {
					fuel[i] = f;
					q.push({ i,f });
				}
			}
			q.pop();
		}
	}
	printf("%d", fuel[n + 1]);


}