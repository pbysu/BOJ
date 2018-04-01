#include<cstdio>
#include<cmath>

double closs;
double r;
int w, h, cnt = 0;

int main() {
	while (1) {
		scanf("%lf", &r);
		if (r == 0) break;
		scanf("%d %d", &w, &h);
		closs = sqrt(w*w + h*h)/2;
		if (closs <= r) {
			printf("Pizza %d fits on the table.\n", ++cnt);
		}
		else
			printf("Pizza %d does not fit on the table.\n", ++cnt);
	}
	return 0;
}