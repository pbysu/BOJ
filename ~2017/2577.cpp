#include<iostream>
using namespace std;
int a, b, c;
int cnt[10];
int main() {
	scanf("%d%d%d", &a, &b, &c);
	int num = a*b*c;
	while (num > 0) {
		cnt[num % 10]++;
		num /= 10;
	}
	for (int i = 0; i <= 9; i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}