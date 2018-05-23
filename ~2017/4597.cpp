#include<iostream>
#include <string.h>

using namespace std;
char arr[40];
int main() {
	int size;
	int check;
	while (1) {
		size = 0;
		check = 0;
		scanf("%s", arr);

		if (arr[0] == '#')
			break;

		size = strlen(arr);
		for (int i = 0; i < size; i++) {
			if (arr[i] == '1') check++;
		}
		if (arr[size - 1] == 'e') {

			if (check%2==0)arr[size - 1] = '0';
			else arr[size - 1] = '1';
		}
		else {
			if (check % 2 == 0)arr[size - 1] = '1';
			else arr[size - 1] = '0';
		}
		printf("%s\n", arr);
	}


	return 0;
}