#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, k;
vector<int> gun;
int main() {
	scanf("%d %d %d", &n, &m, &k);
	gun.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &gun[i]);
	sort(gun.begin(), gun.end());
	int ret = 0;
	for (int x,y, i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		int idxLow = lower_bound(gun.begin(), gun.end(), x) - gun.begin();
		if (abs(gun[idxLow] - x) + y <= k) ret++;
		else{
			int idxHigh = upper_bound(gun.begin(), gun.end(), x) - gun.begin();
			if (idxHigh!=0 &&abs(gun[idxHigh-1] - x) + y <= k) ret++;
		}
	}
	printf("%d\n", ret);
	return 0;
}