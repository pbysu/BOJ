#include<iostream>
#include<algorithm>
using namespace std;
int n;
int num[1000];
int main() {
	scanf("%d", &n);
	int maximum = -1;
	for (int i = 0; i < n; i++){
		scanf("%d", &num[i]);
		maximum = max(num[i], maximum);
	}
	double average = 0;
	for (int i = 0; i < n; i++) {
		average += (float)num[i] / (float)maximum;
	}

	average /= n;
	average *= 100;
	printf("%.2lf", average);
	return 0;
}