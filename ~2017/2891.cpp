#include<cstdio>

using namespace std;
int n, s, r;
int in[13];
int main() {
	scanf("%d %d %d", &n, &s, &r);
	for (int tmp, i = 0; i < s; i++) {
		scanf("%d", &tmp);
		in[tmp] = -1;
	}
	for (int tmp, i = 0; i < r; i++) {
		scanf("%d", &tmp);
		if (in[tmp] == -1)
			s--;
		in[tmp] ++;
	}

	for (int i = 1; i <= n; i++) {
		if (in[i] == -1 && in[i - 1] == 1) in[i] = 0, s--, in[i-1]= 0;
		if (in[i] == -1 && in[1 + i] == 1) in[i] = 0, s--, in[i+1] = 0;
	}
	printf("%d", s);
	return 0;
}