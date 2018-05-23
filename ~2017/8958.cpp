#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
using namespace std;
int main() {
	int tc;
	int ad = 1;
	int total = 0;
	scanf("%d", &tc);
	string arr;
	for (int i = 0; i < tc; i++) {
		cin >> arr;
		ad = 1;
		total = 0;
		int len = arr.length();
		for (int j = 0; j < len; j++) {
			if (arr[j] == 'O') {
				total += ad;
				ad++;
			}
			else {
				ad = 1;
			}
		}
		printf("%d\n", total);
	}
}