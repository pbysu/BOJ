#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n=0, tmp;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &tmp);
		n +=((int)pow(tmp, 2))% 10;
	}
	printf("%d", n % 10);

	return 0;
}