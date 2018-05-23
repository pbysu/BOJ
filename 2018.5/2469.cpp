#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int k, n;
char arr[1001][30];
char up[30], dow[30], ans[30];
int main() {
	scanf("%d%d", &k, &n);
	scanf("%s", &dow);
	strcpy(up, dow);
	sort(up, up + strlen(up));
	for (int i = 0; i < n; i++) {
		scanf("%s", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i][0] == '?')
			break;
		for (int j = 0; j < k; j++) {
			if (arr[i][j] == '-')
				swap(up[j], up[j + 1]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i][0] == '?') {
			break;
		}
		for (int j = 0; j < k; j++) {
			if (arr[i][j] == '-')
				swap(dow[j], dow[j + 1]);
		}
	}

	for (int i = 0; i < k-1; i++) {
		if (up[i] != dow[i]) {
			if (up[i + 1] == dow[i]) {
				swap(up[i], up[i + 1]);
				ans[i] = '-';
			}
			else {
				for (int j = 0; j < k-1; j++) {
					ans[j] = 'x';
				}break;
			}
		}
		else
			ans[i] = '*';
	}
	printf("%s", ans);

	return 0;
}