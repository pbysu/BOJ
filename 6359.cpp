#include<iostream>
#include<vector>
using namespace std;

int t, n;
int main() {
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		vector<int> v(n+1, 0);
		int ans = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= n; j+=i) {
				v[j]++;
			}
			if (v[i] % 2 == 0)
				ans++;
		}
		printf("%d\n", ans);
	}
}