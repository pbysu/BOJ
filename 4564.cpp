#include <iostream>

using namespace std;

int arr[100010];

int main() {
	int n;
	int s = 0;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		printf("%d ", n);
		if (n < 10) { printf("\n"); continue; }
		while (n/10!= 0) {
			int i = 0;
			s = 0;
			int m = 1;
			while (n / 10 != 0) {
				while (n > 0) {
					arr[i] = n % 10;
					n = n / 10;
					i++;
					s++;
				}
				for (int i = 0; i < s; i++) {
					m *= arr[i];
				}
				n = m;
				m = 1;
				i = 0;
				s = 0;
				printf("%d ", n);
			}
			printf("\n");
		}
	}
	return 0;
}