#include<iostream>
#include<algorithm>

using namespace std;
int n, m;
int func(int n, int m,int c) {

	if (n == 0 && c < m)
		return 0;

	int ret = n;
	c += n;

	if (c/n>0) {
		n = c / m;
		c = c%m;
	}
	ret += func(n, m,c);
	return ret;
}
int main() {

	while (scanf("%d %d", &n, &m)!=EOF) {
		int ans =func(n, m,0);
		printf("%d\n", ans);
	}


}