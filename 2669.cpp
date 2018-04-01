#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool arr[100][100];
int main() {
	int x, x1;
	int y, y1;
	int count=0;
	for (int i = 0; i < 4; i++) {
		scanf("%d %d %d %d", &x, &y, &x1, &y1);
		for (int i = x; i < x1; i++) {
			for (int j = y; j < y1; j++) {
				arr[i][j] = true;
			}
		}
	}
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == true) {
				count ++;
			}
		}
	}
	cout << count;
}