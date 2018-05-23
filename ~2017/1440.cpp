#include<iostream>
#include<algorithm>
using namespace std;
int a[3];
int main() {
	scanf("%d:%d:%d", &a[0], &a[1], &a[2]);
	int low12 = 0;
	int more12 = 0;
	int same = 0;
	int hig12 = 0;
	int zero = 1;
	int ans = 1;
	for (int i = 0; i < 3; i++) {
		if (a[i] < 13&& a[i]>0) low12++;
		else if (a[i] >= 0 && a[i] < 60) more12++;
		else zero = 0;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (a[i] == a[j])
				same;
		}
	}
	ans = low12 * 2 * 1;
	while (same > 0) {
		ans = ans / same;
		same--;
	}
	ans*=zero;
	printf("%d", ans);
	return 0;
}