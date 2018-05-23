#include<algorithm>
#include <iostream>	

using namespace std;

long two[41];
int n;
int temp;
int temp1;
long ans = 1;
int n1;
int last;

int main() {
	two[0] = 1;
	two[1] = 1;
	two[2] = 2;

	for (int i = 3; i <= 40; i++) {
		two[i] = two[i - 1] + two[i - 2];
	}

	scanf("%d", &n);
	scanf("%d", &n1);
	temp = 0;


	for (int i = 0; i < n1; i++) {
		scanf("%d", &temp1);
		ans *= two[temp1 - temp -1];
		temp = temp1;
	}
	ans *= two[n - temp];
	if (ans == 0) ans = 1;
	printf("%ld", ans);
}