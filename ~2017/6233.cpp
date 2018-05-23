#include<cstring>
#include<iostream>
#define INF 987654321
using namespace std;
int n, ans = INF, Len;
int cows[5010];
int tmpCow[5010];
char a;
int func(int len) {
	memset(tmpCow, 0, sizeof(tmpCow));
	int ret = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += tmpCow[i];
		if (cows[i] ^ (cnt & 1)) {
			if (i + len > n)
				return INF;
			++cnt;
			++ret;
			tmpCow[i + len] += -1;
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("\n%c", &a);
		cows[i] = a == 'B' ? 1 : 0;
	}
	bool check = false;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int ret = func(i);
		if (ret < ans) {
			ans = ret;
			Len = i;
		}
	}

	printf("%d %d\n", Len, ans);
	return 0;
}