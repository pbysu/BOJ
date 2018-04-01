#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
using namespace std;
char arr[1001][81];
int check[81];
int main() {
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		scanf("%d %s", &check[i], &arr[i][1]);
	}
	for (int i = 1; i <= tc; i++) {
		for (int j = 1; j <= 80; j++) {
			if(j!=check[i]&&arr[i][j]!=NULL)
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}