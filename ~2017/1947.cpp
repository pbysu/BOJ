#include<iostream>
#include<algorithm>

using namespace std;
long long num[1000001];
int n;
int main() {
	scanf("%d", &n);
	num[2] = 1;
	num[3] = 2;
	for (int i = 4; i <= n; i++) {
		num[i] = (((num[i - 1] * (i-1)) % 1000000000) + ((num[i - 2] * (i - 1)) % 1000000000) ) %1000000000;
	}

	printf("%lld", num[n]);


	return 0;
}