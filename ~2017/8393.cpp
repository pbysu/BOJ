#include<iostream>

using namespace std;

int main() {

	long long a = 0;
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		a += i;
	}

	printf("%ld", a);
	return 0;
}