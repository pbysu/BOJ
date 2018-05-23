#include<iostream>
#include<algorithm>
using namespace std;
int row[501];
int col[501];
int n, m;
int main() {
	int cnt = 0;
	scanf("%d %d", &n, &m);
	for (int tmp, i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			cnt = 0;
			while (tmp > 0) {
				if (tmp % 10 == 9) cnt++;
				tmp /= 10;
			}
			row[i] += cnt;
			col[j] += cnt;
		}
	}
	int ans = 0;
	int total = 0;
	for (int i = 0; i < n; i++)
		total+=row[i],ans = max(row[i], ans);
	for (int i = 0; i < m; i++)
		total+=col[i],ans = max(ans, col[i]);
	printf("%d",total/2 -ans);
	return 0;
}