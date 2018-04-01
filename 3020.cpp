#include<cstdio>
#include<algorithm>
using namespace std;
int n, h;
int val;
int hig[500001];
int rever[500001];
bool jd = true;
int main() {
	scanf("%d %d", &n, &h);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &val);

		if (jd) {
			hig[val]++;
			jd = false;
		}

		else {
				rever[val]++;
				jd = true;
		}
	}
	for (int i = h; i >1; i--) {
		hig[i - 1] += hig[i];
		rever[i - 1] += rever[i];
	}
	for (int i = 1; i <= h; i++) {
		hig[i] += rever[h - i + 1];
	}


	sort(hig+1, hig+1 + h);
	int ans = upper_bound(hig+1, hig+1 + h, hig[1]) - &hig[1];
	printf("%d %d\n",hig[1] ,ans);

	return 0;
}