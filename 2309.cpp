#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
int n[10];
int small[2];

void func(int tc,int now, int total,bool jd) {
	if (jd == true) {
		small[tc] = now;
		tc++;
		total -= n[now];
		if (total != 100 && tc == 2) return;
		if (total == 100 && tc == 2) {
			for (int i = 1; i < 10; i++) {
				if (i != small[0] && i != small[1])
				{
					printf("%d\n", n[i]);
				}
			}
		}
		now++;
		if (now > 9) return;

		func(tc, now, total, true);
		func(tc, now, total, false);
	}
	else {
		now++;
		if (now > 9) return;

		func(tc, now, total, true);
		func(tc, now, total, false);
	}


}

int main() {
	int i, j, k;
	int total=0;
	for (i = 1; i < 10; i++) {
		scanf("%d", &n[i]);
		total += n[i];
	}
	sort(n + 1, n + 10);
	func(0,0, total, false);


	return 0;
}