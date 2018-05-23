#include<iostream>
#include<algorithm>

using namespace std;
int input[1001];
int dp[1001];

int func(int pos) {
	if (pos < 1) return 0;
	int &ret = dp[pos];

	if (ret != 0)return ret;
	ret = input[pos];

	int dis = (pos) / 2 + 1;
	for (int i = 1; i < dis; i++) {
		ret = max(func(pos-i)+func(i),ret);
	}
	return ret;
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
	}

	printf("%d", func(n));
	return 0;
}