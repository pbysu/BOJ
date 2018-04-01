#include<cstdio>
#include<algorithm>
#include<cstring>
#include <stdlib.h>
using namespace std;
char a[4], b[4];
int x, y;
int main() {
	scanf("%s", a);
	scanf("%s", b);
	reverse(a, a + strlen(a));
	reverse(b, b + strlen(b));
	x = atoi(a);
	y = atoi(b);
	printf("%d\n", max(x,y));
	return 0;
}