#include<iostream>

using namespace std;

typedef unsigned long long ull;

int main() {
	int tc, cmp;
	scanf("%d", &tc);
	ull value;
	ull mul;
	ull tmp;

	while (tc--) {
		scanf("%d", &cmp);
		value = 0;
		mul = 72057594037927936;

		if (cmp == 1) {
			for (int i = 0; i < 8; i++) {
				scanf("%llu", &tmp);
				value += tmp*mul;
				mul /= 256;
				getchar();
			}
			printf("%llu\n", value);
		}
		else if(cmp==2) {
			scanf("%llu", &value);
			for (int i = 0; i < 7; i++) {
				tmp = value / mul;
				value = value%mul;
				mul /= 256;
				printf("%llu.", tmp);
			}
			printf("%llu\n", value / mul);
		}
	}

	return 0;
}