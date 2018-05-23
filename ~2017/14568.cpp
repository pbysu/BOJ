#include<iostream>
#include <cstring>
using namespace std;

int n;
int check[102][102][102];

int func(int a, int b, int c, int cnt) {
	if (cnt<0)
		return 0;

	int& ret = check[a][b][c];

	if (ret != -1)
		return 0;
	ret = 0;

	if (cnt == 0)
		if (a % 2 == 0 && b >= c + 2&& a!=0 && b!=0&& c!=0)
			return 1;
		else return 0;

	ret += func(a + 2, b, c, cnt - 2);
	ret += func(a, b + 1, c, cnt-1);
	ret += func(a , b, c + 1, cnt - 1);

	return ret;
}
int main() {
	memset(check, -1, sizeof(check));
	scanf("%d", &n);
	printf("%d", func(0, 0, 0, n));
	return 0;
}