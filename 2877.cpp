#include<cstdio>
int n;
int two = 2;
int k = 0;
int main() {
	scanf("%d", &n);
	while (n > two) {
		n -= two;
		two <<= 1;
		k++;
	}
	for (int i = 0; i <= k; i++) {
		two = two >> 1;
		if (n > two) { printf("7"); n -= two;}
		else printf("4");
	}
	return 0;
}