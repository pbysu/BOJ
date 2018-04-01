#include <algorithm>
#include <iostream>
#include<stdio.h>

using namespace std;

bool arr[2100][2100];
char temp[1000];

int main() {
	int tc;
	cin >> tc;
	temp[0]=getchar();
	for (int i = 0; i < tc; i++) {
		scanf("%c", &temp[i]);
	}
	int ans = 0;
	arr[1000][1000] = true;
	ans++;
	int x = 1000, y = 1000;

	for (int i = 0; i < tc; i++) {
		if (temp[i] == 'S') {
			y--;
			if (arr[x][y] != true) {
				arr[x][y] = true;
				ans++;
			}
		}
		else if (temp[i] == 'E') {
			x++;
			if (arr[x][y] != true) {
				arr[x][y] = true;
				ans++;
			}
		}
		else if (temp[i] == 'W') {
			x--;
			if (arr[x][y] != true) {
				arr[x][y] = true;
				ans++;
			}
		}
		else if (temp[i] == 'N') {
			y++;;
			if (arr[x][y] != true) {
				arr[x][y] = true;
				ans++;
			}
		}
	}
	printf("%d", ans);

	return 0;
}