#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int arr[110][110];
int sum[110];
int main() {
	int num = 0;
	int tc = 0;
	int x, x1, y, y1;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		num++;
		scanf("%d %d %d %d", &x, &y, &x1, &y1);
		for (int i = x; i < x1+x; i++) {
			for (int j = y; j < y+y1; j++) {
				arr[i][j] = num;
			}
		}
	}
	int a = 1;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 1; k <= num; k++) {
				if (arr[i][j] == k)
					sum[k]++;
			}
		}
	}
	for (int i = 1; i <= num; i++) {
		printf("%d\n", sum[i]);
	}
}