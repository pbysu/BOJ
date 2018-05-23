#include<iostream>
#include<math.h>

using namespace std;

int main() {
	int n, m;
	scanf("%d\n%d", &n, &m);
	int s, e;
	s = (int)sqrt(n);
	e = (int)sqrt(m)*2;
	long long ans = 0;
	int temp;
	int Min=-1;
	int jd = 0;
	for (int i = s; i <= e; i++) {
		temp = pow(i, 2);
		if (temp >= n&&temp <= m) {
			ans += temp;
			if (jd == 0) { Min = temp; jd = 1; }
		}
	}
	if (Min == -1)printf("%d", Min);
	else
	printf("%lld \n%d", ans,Min);

	return 0;
}