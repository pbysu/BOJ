#include<cstdio>
#include<cstring>
using namespace std;
int cow[11];
int cnt = 0;
int main() {
	int n, m;
	memset(cow, -1, sizeof(cow));
	scanf("%d", &n);
	for (int c, p, i = 0; i < n; i++) {
		scanf("%d %d", &c, &p);
		if (cow[c] != -1 && cow[c] != p)cnt++;
		cow[c] = p;
	}
	printf("%d", cnt);
}