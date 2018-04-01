#include <iostream>
#include <algorithm>
using namespace std;
int inc=0;
int inctemp;
int num[1000];
int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 1; i < n; i++) {
		if (num[i] - num[i - 1]>0) {
			inctemp += num[i] - num[i - 1];
		}
		else {
			inctemp = 0;
		}
		inc = max(inc, inctemp);
	}

	printf("%d", inc);
	return 0;
}