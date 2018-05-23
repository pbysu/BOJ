#include<iostream>
#include<algorithm>
using namespace std;
int n = 3, m = 7;
int main() {
	scanf("%d %d", &n, &m);
	int sumA = 0, sumB = 0;
	int k = 1;
	n--;
	while (n >= k*(k + 1) / 2) {
		sumA += k*k;
		k++;
	}
	k--;
	sumA += (n - k*(k + 1) / 2)*(k + 1);
	k = 1;
	while (m >= k*(k + 1) / 2) {
		sumB += k*k;
		k++;
	}
	k--;
	sumB += (m - k*(k + 1) / 2)*(k + 1);
	
	printf("%d", sumB - sumA);
	return 0;
}