#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int arr[100010];

int main() {
	int size, tc, add = 0, temp;
	scanf("%d %d", &size, &tc);
	for (int i = 1; i <= size; i++) {
		scanf("%d ", &temp);
		arr[i] = arr[i - 1] + temp;
	}
	for (int k = 0; k < tc; k++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		add = arr[n2] - arr[n1-1];
		printf("%d\n", add);
		add = 0;
	}
}