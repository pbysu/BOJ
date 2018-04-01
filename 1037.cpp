#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int arr[80];

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + tc);

	int ans = arr[0] * arr[tc-1];
	printf("%d", ans);

}