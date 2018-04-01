#include<iostream>
#include<string>
using namespace std;

char arr[21];
int main() {
	int tc;
	int tc1;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		scanf("%d %s", &tc1, &arr[0]);

		for (int k = 0; arr[k] != '\0'; k++) {
			for (int j = 0; j < tc1; j++) {
				printf("%c", arr[k]);
			}
		}
		printf("\n");
	}
	return 0;
}