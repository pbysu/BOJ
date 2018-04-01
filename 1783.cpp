#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == 1) return printf("%d", 1), 0;
	if (n == 2) return printf("%d", min(4, (m+1)/2)), 0;
	if (m < 7) return printf("%d", min(4, m)), 0;
	printf("%d", m - 7 + 5);
	return 0;
}