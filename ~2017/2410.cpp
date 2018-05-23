#include<iostream>
#include <algorithm>

using namespace std;
int bin[21];
int dp[1000001][21];
int n;
int MAX = 0;

int func(int pos, int cnt) {
	int ret = 0;

	if (pos == 1||pos==0 || cnt == 0) return 1;
	if (dp[pos][cnt] != 0) return dp[pos][cnt];

	for (int i = cnt; i >=0; i--) {
		if (pos - bin[i] < 0) continue;

		else {
			ret =(ret + func(pos - bin[i], i))%1000000000;
		}
	}


	dp[pos][cnt] = ret;

	return ret;
}

int main() {

	bin[0] = 1;
	scanf("%d", &n);

	for (int i = 1; i < 21; i++) {
		bin[i] = bin[i - 1] * 2;

		if (bin[i] > n) {
			bin[i] = 0;
			MAX = i-1;
			break;
		}
	}

	printf("%d", func(n, MAX));


	return 0;
}