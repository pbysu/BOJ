#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
using namespace std;
int main() {
	int tc;
	cin >> tc;
	int temp = tc;
	int end = 2 * tc - 1;
	int x = 2 * tc;
	for (int i = 0; i < tc-1; i++) {
		for (int j = temp; j < tc; j++) {
			printf(" ");
		}
		for (int j = 0; j < end; j++) {
			printf("*");
		}
		end=end-2;
		temp--;
		printf("\n");
	}

	int flo = tc;
	int k = flo;

		for (int i = 1; i < flo + 1; i++) {
			for (int m = 0; m < k - 1; m++) {
				cout << " ";
			}
			k = k - 1;

			for (int j = 0; j < 2 * i - 1; j++) {
				cout << "*";
			}
			cout << "\n";
		}

	}