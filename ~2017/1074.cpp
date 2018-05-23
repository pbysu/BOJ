#include<iostream>
#include<cmath>
using namespace std;
int n, r, c;
int cnt = -1;
bool check = false;
void func(int y, int x,int l, int cnt) {
	if (y > r || x > c || y + l < r || x + l < c)return;
	if (check)
		return;
	if (l == 1) {
		if (y == r && x == c) {
			printf("%d\n", cnt);
			check = true;
		}
		return;
	}
	l /= 2;

	func(y, x, l,cnt);
	func(y, x+l, l, cnt+l*l);
	func(y + l, x, l, cnt+l*l*2);
	func(y + l, x +l,l, cnt+l*l*3);
}
int main() {
	int startNum = 0;
	scanf("%d%d%d", &n, &r, &c);
	r++, c++;
	func(1,1, 1<<(n),0);
	return 0;
}