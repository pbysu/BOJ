#include<iostream>
#include<algorithm>
using namespace std;
int x, y, w, h;
int main() {
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d", min(w - x,min( h - y,min(x,y))));
	return 0;
}