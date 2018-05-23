#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
using namespace std;
int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		string num;
		cin >> num;
		int end = num.length()-1;
		int last = num[end] - '0';
		if (last % 2 != 0) {
			printf("odd\n");
		}
		else
			printf("even\n");
	}
}