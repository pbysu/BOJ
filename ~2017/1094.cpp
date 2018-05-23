#include<iostream>
#include<algorithm>
using namespace std;
int n;
int func(int num, int pos) {
	if (pos == n)
		return 0;
	int ret = 0;
	if (num + pos > n)
		return ret = func(num / 2, pos);
	else
		return ret +=func(num / 2, pos +num)+1;
	return ret;
}
int main() {
	scanf("%d", &n);
	printf("%d", func(64, 0));

	return 0;
}