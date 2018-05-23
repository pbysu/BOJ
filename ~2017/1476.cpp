#include<iostream>
using namespace std;
int e, s, m;
int main() {
	scanf("%d %d %d", &e, &s, &m);
	int a = 0, b = 0, c = 0;
	int year = 0;
	while (!(a==e&& s==b && c==m)) {
		year++;
		a = a%15+1;
		b = b%28+1;
		c = c%19+1;
	}
	printf("%d",year);
}