#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int n, k, t;
int binCnt = 0;
int fivCnt = 0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		int ans = 1;
		fivCnt = 0;
		binCnt = 0;
		bool jd = false;
		for (int j = 1; j <= k; j++) {
			int tmp = j;
			while (tmp % 5 == 0) {
				fivCnt++;
				tmp /= 5;
			}
			while (tmp % 2 == 0) {
				binCnt++;
				tmp /= 2;
			}
			ans *= tmp;
			ans %= 10;
		}

		binCnt = binCnt - fivCnt;
		for (int k = 0; k < binCnt; k++) {
			ans *= 2;
			ans %= 10;
		}
		printf("%d\n", ans);
	}
}