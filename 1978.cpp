#include <iostream>
#include <stdio.h>
#include<math.h>

using namespace std;

int main()
{
	int check=0;
	int *arr = new int[101];
	for (int i = 0; i < 101; i++) {
		arr[i] = i;
	}
	//초기화

	for (int i = 2; i < 101; i++) {
		for (int j = 2; j <= 101; j++) {
			if (arr[j] != i && arr[j] % i == 0)
				arr[j] = 0;
		}
	}

	int tcase;
	cin >> tcase;

	int *num = new int[tcase];

	for (int i = 0; i < tcase; i++) {
		cin >> num[i];
		for (int j = 2; j < 101; j++) {
			if (num[i] == arr[j]) {
				check++;
			}
		}
	}
	cout << check;
}