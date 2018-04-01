#include<algorithm>
#include<iostream>

using namespace std;
int num;
int t[45];
int small[2];
bool bi = false;
void func(int tc, int now, int sum, bool jd) {
	if (bi == true) return;

	else if (jd == true) {
		tc++;

		if (tc > 3) return;

		sum += t[now];
		if (sum > num) return;
		now++;
		if (now > 45)return;
		if (bi == false && tc == 3 && sum == num) {
			printf("%d\n", 1);
			bi = true;
			return;
		}

		func(tc, --now, sum, true);
		func(tc, now, sum, false);
		func(tc, now, sum, true);
	}
	else {
		now ++;
		if (now > 45)return;
		func(tc, --now, sum, true);
		func(tc, now++, sum, true);
		func(tc, now++, sum, false);

	}
}

int main() {
	for (int i = 1; i < 45; i++) {
		t[i] = (i)*(i + 1) / 2;
	}
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		bi = false;
		scanf("%d", &num);


		func(0, 1, 0, false);
		if (bi == false) printf("%d\n", 0);

	}
	return 0;
}