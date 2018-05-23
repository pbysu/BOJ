#include<iostream>
using namespace std;

int main() {
	int t, n, m;
	int i = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		printf("Case %d: %d\n", i++, n + m);
	}
}