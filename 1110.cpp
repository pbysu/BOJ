#include<cstdio>
using namespace std;
int n, cnt, ten, one, pos;
int main() {
	
	scanf("%d", &n);
	if (n < 10) {
		n *= 10;
	}
	ten = n % 10;
	one = n / 10 + ten;
	pos = ten * 10 + one%10;
	cnt = 1;
	while ( pos != n) {
		ten = pos % 10;
		one = pos / 10 + ten;
		pos = ten * 10 + one%10;
		cnt++;
	}
	printf("%d", cnt);
}