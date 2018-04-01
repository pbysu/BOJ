#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>

using namespace std;

int arr[100][100];
int arr1[100][100];
int answ[100][100];
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int p, q;
	scanf("%d %d", &p, &q);
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < q; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < q; k++)
				answ[i][k] += arr[i][j] * arr1[j][k];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < q; j++) {
			printf("%d ", answ[i][j]);
		}
		printf("\n");
	}
}