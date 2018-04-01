#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n, tmp, maxBits = 20, zero, powTwo;
long long ans = 0;
vector<int> vec;
int main() {
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &vec[i]);
	}
	for (int i = 0; i <=maxBits; i++) {
		zero = 0;
		powTwo = (1 << i);
		for (int j = 0; j < n; j++) {
			if ((vec[j]&powTwo) == 0)
				zero++;
		}
		ans += (long long)zero*(n - zero)*powTwo;
	}
	printf("%lld", ans);
	return 0;
}