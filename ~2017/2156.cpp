#include<algorithm>
#include<cstring>	
#include<iostream>
using namespace std;
int arr[10001];
int dp[3][10001];

int func(int i, int cnt, int n) {


	int &ret = dp[cnt][i];


	if (dp[cnt][i] !=-1 )
		return ret;

	if (i >= n)
		return ret = 0;

	if (cnt == 0) {
		return ret = max(func(i + 1, 1, n), max(func(i + 1, 2, n),func(i+1,0,n)));
	}
	if (cnt == 1) {
		return ret = arr[i] + func(i + 1, 0, n);
	}

	return ret = arr[i] + arr[i + 1] + func(i + 2, 0, n);

}

int main() {
	int n;
	
	scanf("%d", &n);
	memset(dp,-1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d\n", max(func(0, 0, n), max(func(0, 1, n), func(0, 2, n))));

	return 0;
}