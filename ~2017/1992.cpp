#include<iostream>
using namespace std;
int in[65][65];
int n;
void func(int r, int c, int len) {
	int ex = in[r][c];
	bool jd = true;
	for (int i = r; i < len + r; i++) {
		for (int j = c; j < len + c; j++) {
			if (in[i][j] != ex) {
				jd = false;
				break;
			}
		}
		if (!jd) break;
	}
	if (!jd) {
		printf("(");
		func(r, c, len / 2);
		func(r, len / 2 + c, len / 2);
		func(len / 2 + r, c, len / 2);
		func(len / 2 + r, len / 2 + c, len / 2);
		printf(")");
	}
	else {
		printf("%d", ex);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &in[i][j]);
		}
	}
	func(1, 1, n);
	return 0;
}