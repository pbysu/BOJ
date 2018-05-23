#include<iostream>
#include<algorithm>
using namespace std;
int n, m, k;
int cnt = 1;
int main() {
	scanf("%d %d %d", &n, &m, &k);
	if (m > k) swap(m, k);
	while (!(m==k ||((m&1)&& (m+1==k)))) {
		cnt++;
		if ((m & 1)) m = (m + 1) / 2;
		else m /= 2;
		if ((k & 1)) k = (k + 1) / 2;
		else k /= 2;
		if (m == 0) {
			printf("-1\n");
		}
	}
	printf("%d", cnt);
	return 0;
}