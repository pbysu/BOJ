#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int w, h;
	int p, q;
	int t;

	scanf("%d %d", &w, &h);
	scanf("%d %d", &p, &q);
	cin >> t;
	int x = 1, y = 1;
	for (int i = 0; i < t; i++) {
		if (p == w||p==0) {
			x = x*-1;
		}
		if (q == h||q==0) {
			y = y*-1;
		}
		p = p + x;
		q = q + y;

	}
	printf("%d %d", p, q);
}