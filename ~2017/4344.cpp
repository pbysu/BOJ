#include<iostream>
#include<vector>
using namespace std;
int tc, n;
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		vector<int> v(n, 0);
		int avg = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			avg += v[i];
		}
		avg /= n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] > avg)
				cnt++;
		}
		printf("%.3f\%%\n", ((double)cnt/ n)*100);
	}
}