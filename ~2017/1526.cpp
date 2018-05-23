#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define INF 987654321
using namespace std;
int num;

int func(int digit,int ex, int next) {
	if (digit < 0)
		return -INF;
	if (digit == 0) {
		int pos = ex + next;
		if (pos > num)
			return -INF;
		return pos;
	}
	int ret = 0;
	int tmp = 0;
	int pos = ex + next*pow(10, digit);
	if (pos > num)
		return -INF;
	ret = func(digit - 1,pos, 7);
	if (ret ==-INF) {
		ret=func(digit - 1, pos, 4);
		if (ret ==INF) {
			return -INF;
		}
	}

	return ret;
}
int main() {
	scanf("%d", &num);
	int k = -1;
	int tmp = num;
	while (tmp > 0) {
		k++;
		tmp /= 10;
	}
	int ans = max(func(k,0, 4), max(func(k,0, 7),func(k-1,0, 7)));
	printf("%d", ans);
	return 0;
}