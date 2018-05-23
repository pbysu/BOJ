#include<cstdio>
#include<algorithm>
using namespace std;

int total = 0, cnt;
int maximum = 0;
int main() {
	scanf("%d", &cnt);
	for (int tmp,i = 0; i < cnt; i++) {
		scanf("%d", &tmp);
		total += tmp;
		maximum = max(maximum, tmp);
	}

	printf("%d\n", total - maximum);
}