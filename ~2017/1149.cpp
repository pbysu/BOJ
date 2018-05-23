#include<iostream>
#include<algorithm>

using namespace std;

int x, y, z;
int n;

void func(int a, int b, int c) {

	int xtmp = min(y,z) + a;
	int ytmp= min(x, z) + b;
	int ztmp = min(x, y) + c;
	x = xtmp, y = ytmp, z = ztmp;
}

int main() {
	
	int a, b, c;
	scanf("%d", &n);

	scanf("%d %d %d", &x, &y, &z);

	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		func(a, b, c);
	}

	printf("%d", min(x, min(y, z)));
	return 0;
}