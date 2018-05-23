#include<iostream>
#include<algorithm>
using namespace std;
int n;
double arr[21];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
	}

	sort(arr, arr + n);
	double ex = arr[0];
	for (int i = 1; i < n; i ++) {
		ex = (ex + arr[i]) / 2;
	}
	printf("%.6lf", ex);
	return 0;
}