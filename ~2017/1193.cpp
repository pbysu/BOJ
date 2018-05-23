#include<iostream>
#include<algorithm>

using namespace std;
int x;
int n = 1;
int temp;
int main() {

	scanf("%d", &x);

	while (true) {
		if (x >= n*(n + 1) / 2) n++;
		else
			break;
	}

	temp = x - n*(n + 1) / 2;

	if (temp != 0)
		temp = x - n*(n - 1) / 2;

	if (temp == 0) {
		if (n % 2 == 0) {
			printf("%d/%d\n", 1, --n);
		}

		else
			printf("%d/%d\n", --n, 1);
	}

	else {
		if (n % 2 == 0) {
			printf("%d/%d\n", temp, n - temp + 1);
		}

		else
			printf("%d/%d\n", n - temp + 1, temp);
	}

	return 0;
}