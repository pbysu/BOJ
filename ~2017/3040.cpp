#include <iostream>

using namespace std;

int n[10];
int main() {
	int to = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &n[i]);
		to += n[i];
	}
	int jd = 0;
	for (int i = 0; i < 9; i++) {
		if (jd == 1) break;
		for (int j = i; j < 9; j++) {
			if (to - (n[i] + n[j]) == 100) {
				n[i] = 0;
				n[j] = 0;
				jd = 1;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (n[i] != 0) printf("%d\n", n[i]);
	}
	return 0;
}