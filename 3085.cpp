#include<algorithm>
#include<iostream>
using namespace std;
int a[] = { 1,-1 };

char board[52][52];

int large = 1;

int incY(int i, int j, int cnt) {
	if (board[i][j] == board[i + 1][j])
		cnt++;

	else return cnt;

	return(incY(i + 1, j, cnt));
}
int dicY(int i, int j, int cnt) {
	if (board[i][j] == board[i - 1][j])
		cnt++;

	else return cnt;

	return(dicY(i - 1, j, cnt));
}

int incX(int i, int j, int cnt) {
	if (board[i][j] == board[i][j + 1])
		cnt++;

	else return cnt;

	return(incX(i, j + 1, cnt));
}
int dicX(int i, int j, int cnt) {
	if (board[i][j] == board[i][j - 1])
		cnt++;

	else return cnt;

	return(dicX(i, j - 1, cnt));
}


int main() {
	int size;
	scanf("%d", &size);
	getchar();

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			scanf("%c", &board[i][j]);
		}
		getchar();
	}
	char temp;
	int xcnt, ycnt;
	xcnt = ycnt = 0;

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			for (int k = 0; k < 2; k++) {
				if (board[i + a[k]][j] >= 'A' && board[i + a[k]][j] <= 'Z') {

					swap(board[i][j], board[i + a[k]][j]);

					ycnt = incY(i, j, 0) + dicY(i, j, 0);
					xcnt = incX(i, j, 0) + dicX(i, j, 0);
					large = max(xcnt, max(ycnt, large));

					swap(board[i][j], board[i + a[k]][j]);
				}

				if (board[i][j + a[k]] >= 'A' && board[i][j + a[k]] <= 'Z') {
					swap(board[i][j], board[i][j + a[k]]);

					ycnt = incY(i, j, 0) + dicY(i, j, 0);
					xcnt = incX(i, j, 0) + dicX(i, j, 0);

					large = max(xcnt, max(ycnt, large));

					swap(board[i][j], board[i ][j + a[k]]);
				}


			}
		}
	}

	printf("%d", large+1);
	return 0;
}