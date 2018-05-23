#include<iostream>
using namespace std;
typedef long long ll;
char arr[50][50];
char arr1[50][50];
bool cmped[50][50];
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", arr[i]);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr1[i]);
		for (int j = 0; j < m; j++)
			if (arr[i][j] != arr1[i][j])
				cmped[i][j] = true;
	}
	n -= 2;
	m -= 2;
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (cmped[i][j]) {
				ans++;
				for (int r = i; r < i + 3; r++)
					for (int c = j; c < j + 3; c++)
						cmped[r][c] = cmped[r][c] ? false : true;

			}
	n += 2, m += 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (cmped[i][j]) {
				printf("-1\n");
				return 0;
			}
	printf("%d", ans);
	return 0;
}