#include<cstdio>
#include<algorithm>
#include<vector>	
#include<cstring>
#define INF 1e9;
using namespace std;
int in[1001];
bool visited[1001];
int dp[1001][1001];
int n, k, remin;

int func(int pos, int idx) {
	if (pos > k) return INF;
	if (idx == n)return 0;
	int &ret = dp[pos][idx];
	if (ret != -1)
		return ret;
	ret = 0;
	ret += min(func(pos+1+in[idx], idx + 1), func(in[idx], idx + 1)+(k-pos)*(k-pos));
	return ret;
}


int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int tmp, i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	printf("%d\n", func(in[0],1));

	return 0;
}