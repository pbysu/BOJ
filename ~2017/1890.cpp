#include<iostream>
#include<vector>
using namespace std;
vector<vector<long long>> dp;
int t;

long long func(int r, int c, vector<vector<long long>>& count) {
	long long& ret = dp[r][c];
    //dp 는 &ret 으로 배열 가져오기 : 정형화
	if (ret != -1)
		return ret;
    //기저 조건 정형화
	ret = 0;
	if (r == t - 1 && c == t - 1)return ret = 1;
	int temp = count[r][c];
	if (temp == 0) return 0;
	if (c + temp < t) ret += func(r, c + temp, count);
	if (r + temp < t) ret += func(r+temp, c, count);
	return ret;
}

int main() {
	scanf("%d", &t);
	int temp;
	vector<vector<long long>> count(t, vector<long long>( t,0 ));
	dp.resize(t, vector<long long>(t, -1));
	count[0][0] = 1;
	for (int i = 0; i < t; i++) {
		for (int k = 0; k < t; k++) {
			scanf("%d", &count[i][k]);
		}
	}
	printf("%lld", func(0,0,count));
	return 0;
}