#include<cstdio>
#include<cstring>
#include<vector>	
#include<algorithm>
#include<map>
using namespace std;
map<int, int> ma;
typedef long long ll;
int N, k, a[1000001], tmp, u, v;
ll sum[1000001];
void something(int jump, int c) {
	int i = 0;
	while (i < N) {
		a[i] += c;
		i = i + jump;
	}
}
int main() {
	scanf("%d %d", &N, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &tmp);
		ma[tmp]++;
	}
	for (auto it = ma.begin(); it != ma.end(); it++) {
		something(it->first, it->second);
	}
	sum[0] = a[0];
	for (int i = 1; i < N; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	scanf("%d", &tmp);
	for (int i = 0; i < tmp; i++) {
		scanf("%d %d", &u, &v);
		if (u != 0) {
			printf("%lld\n", sum[v] - sum[u - 1]);
		}
		else {
			printf("%lld\n", sum[v]);
		}
	}

	return 0;
}