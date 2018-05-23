#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 987654321

int arr[264];
int dp[300001];
using namespace std;

int func(int cost) {
	if (cost == 0) return 0;
	int&ret = dp[cost];
	if (ret != -1) return ret;
	ret = INF;
	int k = 0;
	while (cost - arr[k] >= 0) {
		ret = min(func(cost - arr[k]) + 1, ret);
		k++;
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	arr[0] = 0;
	int num;
	scanf("%d", &num);
	for (int i = 1; i < 264; i++) {
		arr[i] = arr[i - 1] + (i)*(i+1)/2;
	}
	printf("%d", func(num));
	return 0;
}