#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n,temp;
	cin >> n;
	temp = n;
	for (int i = 0; i < n-1; i++) {
		for (int j=0; j < temp-1; j++) {
			printf(" ");
		}
		for (int k = 0; k <= i; k++) {
			printf("*");
		}
		temp--;
		printf("\n");
	}
	temp = n;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k <= i-1; k++) {
			printf(" ");
		}
		for (int j = 0; j < temp; j++) {
			printf("*");
		}

		temp--;
		printf("\n");
	}
}