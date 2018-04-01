#include <iostream>
#include <algorithm>

using namespace std;
int num[1000000];
int k = 0;
int j = 0;
int i = 0;
int main() {
	while (scanf("%1d", &num[k]) != EOF) {
		k++;
	}
	if (k % 3 == 1) {
		printf("%d", num[0]);
		j = 1;
	}
	else if (k % 3 == 2) {
		printf("%d", num[0] * 2 + num[1]);
		j = 2;
	}
	while (j<k) {
		i++;
		if (i % 3 == 0) {
			printf("%d", num[j - 2] * 4 + num[j - 1] * 2 + num[j]);
			i = 0;
		}
		j++;
	}
	return 0;
}