#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
double dir[4];
bool check[30][30];
int table[30][30];
int n;
double ret = 1;

double func(int r, int c, int cnt) {
	if (cnt == n)
		return 1;
	int tr, tc;
	double ret = 0;
	
	if (cnt == n) {
		return 1;
	}

	check[r][c] = true;
	for (int i = 0; i < 4; i++) {
		tr = r + dr[i];
		tc = c + dc[i];
		if(check[tr][tc] == false )
		ret += func(tr, tc, cnt+1)*dir[i];
	}
	check[r][c] = false;
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		scanf("%lf", &dir[i]);
		dir[i] /= 100;
	}
	printf("%.10lf", func(15, 15, 0));
	return 0;
}