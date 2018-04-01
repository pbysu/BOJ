#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 100000000000
using namespace std;
typedef long long ll;
int tc, k,idx, cnt;
ll tmp, num;

bool check[10];


int main() {
	scanf("%d", &tc);
	check[0] = true;
	for (int i = 1; i <= tc; i++) {
		scanf("%lld", &num);
		k = 2;
		memset(check, false, sizeof(check));
		cnt = 0;
		tmp = num;
		if (tmp == 0) {
			printf("Case #%d: INSOMNIA\n", i); continue;
		}
		
		while (tmp < INF) {
			while (tmp) {
				idx = tmp % 10;
				tmp /= 10;
				if (!check[idx]) {
					cnt++;
					check[idx] = true;
					if (cnt == 10)
						break;
				}
			}
			if (cnt == 10)
				break;

			tmp = num*k++;
		}
		if(cnt==10) printf("Case #%d: %lld\n", i, num*(k-1));
		else printf("Case #%d: INSOMNIA\n", i);
	}
	return 0;
}