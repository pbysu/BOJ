#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;
int N, m, M, T, R;
vector<int> v;
int func(int now, int work) {
	if (work == 0) {
		return 0;
	}
	int ret = INF;
	if (now + T <= M) {
		ret = min(func(now + T, work - 1)+1,ret);
	}
	else if (now - R >= m) {
		ret = min(func(now - R, work) + 1, ret);
	}
	else if(now!=m) ret = min(func(m, work) + 1, ret);
	return ret;
}
int main() {
	scanf("%d%d%d%d%d", &N, &m, &M, &T, &R);

	int ret = func(m, N);
	if (ret == INF) ret = -1;
	printf("%d",ret);
	return 0;
}