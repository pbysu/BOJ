#include<cstdio>
int x1, x2, y1, y2, p1, p2, q1, q2;
bool f1, f2;
long long temp;
int main() {
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &p1, &q1, &p2, &q2);
	temp = (long long)((x1*y2) + (x2*q1) + (p1*y1)
		- (y1*x2 + y2*p1 + q1*x1));

	if (temp == 0) {
		printf("0");
		return 0;
	}
	if (temp > 0)f1 = true;
	else f1 = false;
	temp = 0;
	temp = (long long)((x1*y2) + (x2*q2) + (p2*y1)
		- (y1*x2 + y2*p2 + q2*x1));

	if (temp == 0) {
		printf("0");
		return 0;
	}
	if (temp > 0)f2 = true;
	else f2 = false;
	if (f1&&f2) printf("0");
	else if (f1 || f2) printf("1");
	else printf("0");

	return 0;
}