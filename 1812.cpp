#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000];
int arr1[1000];

int main() {
	int tc;
	int total = 0;
	int part = 0;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d", &arr[i]);
		total += arr[i];
	}
	total = total / 2;

	if (tc % 2 == 1) {
		int k = tc / 2;
		for (int i =1; i <= k; i++) {
			part += arr[2 * i-1];
		}
		int temp = total - part;
		printf("%d\n", temp);
		for (int i = 0; i < tc-1; i++) {
			temp = arr[i] - temp;
			printf("%d\n", temp);
		}
	}
	else {
		int k = tc / 2;
		for (int i = 1; i < k; i++) {
			part += arr[2 * i - 1];
		}
		int temp = total - part;
		printf("%d\n", temp);
		for (int i = 0; i < tc ; i++) {
			temp = arr[i] - temp;
			printf("%d\n", temp);
		}
	}


	return 0;
}