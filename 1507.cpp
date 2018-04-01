#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int table[21][21];
bool check[21][21];
int main() {
	int n;
	scanf("%d", &n);
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &table[i][j]);
			if (i<j)
				total += table[i][j];
		}
	}

	int ans = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (table[i][k] + table[k][j] < table[i][j])
					return printf("-1");
				if (i!=k && k!=j &&table[i][k] + table[k][j] == table[i][j] && !check[i][j]) {
					check[i][j] = true;
					ans += table[i][j];
				}
			}
		}
	}

	printf("%d",total- ans);
	return 0;
}