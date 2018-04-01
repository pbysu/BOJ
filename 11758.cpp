#include<cstdio>
int x1, x2, x3, y1, y2, y3;
int main() {
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	int temp = x1*y2 + x2*y3 + x3*y1;
	temp -=(y1*x2 + y2*x3 + y3*x1);
	if (temp == 0)
		printf("0");
	else if (temp > 0)
		printf("1");
	else
		printf("-1");
	return 0;
}