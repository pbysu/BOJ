#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>

using namespace std;

int main() {
	int m, h, th;
	scanf("%d %d", &h, &m);
	int t;
	scanf("%d", &t);

	th = t / 60;
	t = t % 60;
	h += th;
	m = m + t;

	if (m >= 60) {
		m = (m) % 60;
		h++;
	}

	if (h >= 24) {
		h = h % 24;
	}
	printf("%d %d", h, m);
}