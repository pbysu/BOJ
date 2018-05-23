#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

char arr[110][110];

int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		scanf("%s", arr[i]);
	}
	int temp;
	cin >> temp;

	if (temp == 1) {
		for (int i = 0; i <tc; i++) {
			printf("%s\n", arr[i]);
		}
	}

	else  if (temp == 2) {
		for (int i = 0; i < tc; i++) {
			int size = strlen(arr[i]);
			reverse(arr[i], arr[i] + size);
			printf("%s\n", arr[i]);
		}
	}
	else {
		for (int i = tc-1; i >= 0; i--) {
			printf("%s\n", arr[i]);
		}
	}

}