#include<iostream>
#include<string>

using namespace std;
char arr[9][9];

int main()
{
	int total = 0;

	for (int i = 1; i< 9; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i<9; i++) {
		for (int j = 0; j <8; j++) {
			if (i % 2 == 1 && j % 2 != 1 && arr[i][j] == 'F') {
				total++;
			}
			else if (i % 2 == 0 && j % 2 == 1 && arr[i][j] == 'F') {
				total++;
			}
		}
	}

	printf("%d", total);
}