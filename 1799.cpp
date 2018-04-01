#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<pair<int, pair<int, pair<int, int>>>, int> m;

int n;
int visited[11][11];
int rightHIghLeftLow[21];
int leftHighRightLow[21];
int Max = 0;

void func(bool ca, int r, int c, int cnt) {
	Max = Max < cnt ? cnt : Max;

	if (c > n) {
		r++;
		if (r >= n) return;

		if (ca == 0) {
			if ((r+1) % 2 == 0)
				c = 1;
			else
				c = 0;
		}
		else {
			if ((r+1) % 2 == 0)
				c = 0;
			else
				c = 1;
		}

	}

	if (visited[r][c] == 1 && rightHIghLeftLow[r + c] == 0 
		&& leftHighRightLow[n - 1 + r - c] == 0) {
		visited[r][c]--;
		rightHIghLeftLow[r + c]--;
		leftHighRightLow[n - 1 + r - c]--;
		func(ca, r, c+2, cnt+1);
		visited[r][c]++;
		rightHIghLeftLow[r + c]++;
		leftHighRightLow[n - 1 + r - c]++;
	}
	func(ca , r, c+ 2,cnt);
	return;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &visited[i][j]);
		}
	}
	int ans = 0;

	func(0, 0, 0, 0);
	ans = Max;
	Max = 0;
	func(1, 0, 1, 0);
	ans += Max;
	printf("%d", ans);
	return 0;
}