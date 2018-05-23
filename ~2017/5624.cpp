#include<iostream>
#include<vector>
#include<algorithm>
#define zero 200000
using namespace std;
int n;
int dp[400010];
vector<int> v;
int main() {
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[v[i] - v[j] + zero]) {
				cnt++;
				break;
			}
		}
		for (int j = 0; j <= i; j++) {
			dp[v[i] + v[j] + zero] = 1;
		}
	}
	printf("%d", cnt);
	return 0;
}