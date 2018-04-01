#include<iostream>
using namespace std;
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	int colChange = n / 2;
	int rowChange = m / 2;
	int siz = colChange + rowChange;
	printf("%d\n", siz);

	for (int i = 1; i <= colChange; i++) {
		printf("%d %d %d %d\n",  2 * i,1,   2 * i,m);
	}
	for (int i = 1; i <= rowChange; i++) {
		printf("%d %d %d %d\n", 1, 2 * i,n, 2 * i);
	}
	return 0;
}