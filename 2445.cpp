#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	int k = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		
		for (int j = 0; j < 2 * (n -1 - k); j++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
		k++;
	}
	k =2;
	int temp = n-1;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < temp; j++) {
			printf("*");
		}
		for (int j = 0; j < k; j++) {
			printf(" ");
		}
		for (int j = 0; j < temp; j++) {
			printf("*");
		}
		k += 2;
		temp -- ;
		printf("\n");
	}
}