#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define INF 987654321
using namespace std;
int t, target, n, cas, nm, m;
int dp[1000010];
vector<int> v;

void check(int num) {
	int digit;
	bool flag;
	int cnt = 0;
	for (int i = 1; num / i != 0; i *= 10) {
		flag = false;
		digit = (num % (i * 10)) / i;
		for (int j = 0; j < n; j++) {
			if (v[j] == digit) {
				cnt++;
				flag = true;
				break;
			}
		}
		if (!flag)
			break;
	}
	if (flag)
		dp[num] = 0;
	else
		dp[num] = -1;
}

int func(int num) {
	int &ret = dp[num];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 2; i*i <= num; i++) {
		if ((num%i) == 0 && dp[i] == 0)
			ret = min(ret, func(num / i) + 1);
	}
	return ret;
}
int main() {
	scanf("%d", &t);
	cas = 0;
	while (t--) {
		cas++;
		n = 0;
		v.clear();
		int nm;
		scanf("%d", &nm);
		n = nm;
		for (int tmp, i = 0; i < nm; i++) {
			scanf("%d", &tmp);
			 v.push_back(tmp);
		}
		memset(dp, -1, sizeof(dp));
		//for (int tmp, i = 0; i < 10; i++) {
		//	scanf("%d", &tmp);
		//	if (tmp) n++, v.push_back(i);
		//}
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &target);
			for (int j = 1; j <= target; j++) {
				check(j);
			}
			int ans = func(target);
			if (ans != INF)	printf("%d\n",ans);
			else printf("-1\n");
		}
		
	}
	return 0;
}