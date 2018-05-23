#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
bool arr[1001];

int main() {
	int count = 0;
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		arr[i] = true;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (arr[j] == false)
				continue;
			arr[j] = false;
			++count;
			if (count == k) {
				printf("%d ", j);
				break;
			}
		}
	}
}