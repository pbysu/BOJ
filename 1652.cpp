#include<iostream>
using namespace std;

int table[101][101];
int cCheck[101][101];
int rCheck[101][101];
int dr[2] = { 0, 1 };
int dc[2] = { 1, 0 };
int n;
char c;
int rfunc(int r, int c) {
	rCheck[r][c] = true;
	int tr = r + dr[1];
	int tc = c + dc[1];
	int ret = 1;
	if (tr >= 0 && tr < n && tc >= 0 && tc < n)
		if (!table[tr][tc])
			ret += rfunc(tr, tc);
	return ret;
}
int cfunc(int r, int c) {
	cCheck[r][c] = true;
	int tr = r + dr[0];
	int tc = c + dc[0];
	int ret = 1;
	if (tr >= 0 && tr < n && tc >= 0 && tc < n)
		if (!table[tr][tc])
			ret +=cfunc(tr, tc);
	return ret;
}
int main() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%c", &c);
			if (c == '.') table[i][j] = 0;
			else if (c == 'X')table[i][j] = 1;
		}
		getchar();
	}
	int r = 0, c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[i][j] == 0) {
				if (rCheck[i][j] == false)
					if(rfunc(i, j)>=2) r++;
				if (cCheck[i][j] == false)
					if( cfunc(i, j)>=2) c++;
			}
		}
	}

	printf("%d %d", c, r);
}