#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int t, n, m, k;
int arr[100004];
ll sum;
ll ex;
int cnt = 0;
int main() {
	scanf("%d", &t);
	while (t--) {
		cnt = 0;
		ex = 0;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		for (int j = 0; j < m; j++) {
			ex += arr[j + 1];
		}
		if (ex < k)
			cnt++;

		for (int i = 2; i <= n - m; i++) {
			sum = ex - arr[i-1] + arr[i + m-1];
			if (sum < k)
				cnt++;
			ex = sum;
			sum = 0;
		}

		if (m != n) {
			for (int i = n - m + 1; i <= n; i++) {
				int idx = i + m - 1;
				if (idx > n) idx = idx % (n + 1) + 1;
				sum = ex - arr[i - 1] + arr[idx];
				if (sum <k)
					cnt++;
				ex = sum;
				sum = 0;
			}
		}

		printf("%d\n", cnt);
	}
	return 0;
}