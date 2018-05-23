#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<double, double> pii;
pii area[3], t;
double mx, my, S;
int n, cnt;
double check(pii p, pii q, pii r) {
	return fabs((p.first*(q.second - r.second)
		+ q.first*(r.second - p.second)
		+ r.first* (p.second - q.second)) / 2
	);
}
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%lf %lf", &area[i].first, &area[i].second);
		mx += area[i].first;
		my += area[i].second;
	}
	mx /= 3; my /= 3;
	S = check(area[0], area[1], area[2]);
		scanf("%d", &n);
	while (n--) {
		scanf("%lf %lf", &t.first, &t.second);
		if (S == check(t, area[1], area[2]) + check(area[0], t, area[2])
			+ check(area[0], area[1], t)) {
			cnt++;
		}
	}
	printf("%.1lf\n%d", S, cnt);
	return 0;
}