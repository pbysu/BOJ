#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
using namespace std;
int main() {

	int tc;
	int n1, n2;
	int temp = 1;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {

		temp = 1;
		scanf("%d %d", &n1, &n2);
		n1 = n1 % 10;
		if (n1 == 0) {
			temp = 10;
		}
		else {
			for (int j = 0; j < n2; j++) {
				temp = ((temp*n1) % 10);
				if (temp == 0) {
					temp = 10;
				}
			}
		}
		printf("%d\n", temp);
	}
}