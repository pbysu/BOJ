#include<iostream>
#include<algorithm>
using namespace std;
int n[100000];
int m[100000];
int mi = 987654321;


int gcd(int x, int y) {
	if (x < y) swap(x, y);
	if (y == 0)return x;
	else return gcd(y, x%y);
}
int main() {
	int tc;
	cin >> tc;
	int gc;
	for (int i = 0; i < tc; i++) {
		scanf("%d", &n[i]);

	}
	gc = n[1] - n[0];

	for (int i = 1; i < tc; i++) {
		m[i - 1] = n[i] - n[i - 1];
		gc = gcd(gc, m[i - 1]);
	}

	int ans = 0;
	for (int i = 0; i < tc - 1; i++) {
		if (m[i] / gc != 0) {
			ans += m[i] / gc - 1;
		}
	}

	printf("%d", ans);
	return 0;
}