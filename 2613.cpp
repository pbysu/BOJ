#include<iostream>
#include<algorithm>
using namespace std;
int n, m, MA;
int v[301];
int main() {
	scanf("%d %d", &n, &m);
	
	if (n == m) {
		
		for (int tmp, i = 0; i < n; i++) {
			scanf("%d", &tmp);
			MA = max(tmp, MA);
		}
		printf("%d\n", MA);
		for (int i = 0; i < n; i++) {
			printf("1 ");
		}
		return 0;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]), MA += v[i];


	int left = 0;
	int right = MA+1;
	int mid, sum, group;

	while (left <= right) {
		mid = (left + right) >> 1;
		group = sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += v[i];
			if (sum > mid) {
				sum = v[i];
				group++;
				if (group > m)
					break;
			}
		}
		if (sum + v[n - 1] > mid) group += 2;
		else group++;

		if (group > m) left = mid + 1;
		else right = mid - 1;
	}
	sum = 0;
	printf("%d\n", left);
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += v[i];
		if (sum > left) {
			sum = v[i];
			printf("%d ", cnt);
			cnt = 0;
		}
		cnt++;
	}
	if (n == 1)
		cnt = 1;
	else {
		if (sum + v[n - 1] > mid) cnt += 2;
		else cnt++;
	}
	printf("%d", cnt);

	return 0;
}