#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
vector<int> save;
typedef long long ll;
int func(int cur, ll mul, int st, ll sqr) {
	if (cur == save.size()) return 0;
	int ret = 0;
	for (int i = cur + 1; i < save.size(); i++) {
		int x = mul*save[i];
		if (st & 1) ret -= sqr / x;
		else ret += sqr / x;
		ret += func(i, mul*save[i], st ^ 1, sqr);
	}
	return ret;
}
int main() {
	ll num, tnum, sqr; int cnt;
	while (1) {
		scanf("%lld", &num);
		if (num == 0)return 0;
		save.resize(0); tnum = num; sqr = sqrt(num);cnt = 0;
		for (ll i = 2; i <= sqr; i++) {
			if (tnum%i == 0) save.push_back(i);
			while (tnum%i == 0)tnum /= i;
		}
		if (tnum != 1) save.push_back(tnum);
		printf("%lld\n", num-func(-1,1,0,num));
	}

	return 0;
}