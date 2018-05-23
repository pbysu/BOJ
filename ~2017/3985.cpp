#include<iostream>
using namespace std;
int n, m;
bool in[1010];
int think, real;
int u, v, cnt;
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	think = real = -1;
	for (int s, e, i = 0; i < m; i++) {
		cnt = 0;
		scanf("%d %d", &s, &e);
		if (e - s > think) {
			think = e-s;
			u = i + 1;
		}
		for (int j = s; j <= e; j++) {
			if (!in[j]) {
				in[j] = true;
				cnt++;
			}
		}
		if (cnt > real) {
			real = cnt;
			v = i + 1;
		}
	}
	printf("%d\n%d", u, v);
	return 0;
}