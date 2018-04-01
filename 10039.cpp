#include<iostream>
using namespace std;

int n, tmp;
int main() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &tmp);
		if (tmp < 40)
			sum += 40;
		else
			sum += tmp;
	}
	printf("%d", sum / 5);

	return 0;
}