#include <iostream>
#include <algorithm>
using namespace std;

char check[52][52];

int a[2] = { 1,-1 };

int main() {

	int col, row;

	scanf("%d %d", &col, &row);
	getchar();

	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			scanf("%c", &check[i][j]);
		}
		getchar();
	}
	int MAX = 0;
	int temp;
	int p, q;
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			temp = 0;
			if (check[i][j] == '.') {
				for (int k = 0; k < 2; k++) {
					if (check[i + a[k]][j] == 'o') {
						temp++;
					}
					if (check[i][j + a[k]] == 'o') {
						temp++;
					}
					if (check[i + a[k]][j + a[k]] == 'o') {
						temp++;
					}
					if (check[i + a[k]][j - a[k]] == 'o') {
						temp++;
					}
				}
			}
			if (temp > MAX) {
				MAX = temp;
				p = i;
				q = j;
			}
		}
	}

	check[p][q] = 'o';
	int total = 0;
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			if (check[i][j] == 'o') {
				temp = 0;
				for (int k = 0; k < 2; k++) {
					if (check[i + a[k]][j] == 'o') {
						temp++;
					}
					if (check[i][j + a[k]] == 'o') {
						temp++;
					}
					if (check[i + a[k]][j + a[k]] == 'o') {
						temp++;
					}
					if (check[i + a[k]][j - a[k]] == 'o') {
						temp++;
					}
				}
				total += temp;
			}

		}
	}


	printf("%d\n", total/2);


	return 0;
}