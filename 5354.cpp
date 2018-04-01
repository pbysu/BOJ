#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
char arr[10][10];
int main() {
	int tc;
	int len;
	cin >> tc;
	while (tc>0) {
		scanf("%d", &len);
		for (int i = 0; i < len; i++) {
			if (i == 0||i==len-1) {
				for (int j = 0; j < len; j++) {
					printf("#");
				}
				printf("\n");
			}
			else {
				for (int j = 0; j < len; j++) {
					if (j == 0 || j == len - 1)
						printf("#");
					else
						printf("J");
				}
				printf("\n");
			}

		}
		tc--;
		printf("\n");
	}
}