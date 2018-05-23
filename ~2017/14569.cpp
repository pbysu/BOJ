#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
vector<unsigned long long>tim;
vector<unsigned long long>id;
int main() {
	int n, k, tmp, q;
	scanf("%d", &n);
	tim.resize(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &tmp);
			tim[i] += pow(2, tmp-1);
		}
	}
	scanf("%d", &k);
	id.resize(k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &q);
		for (int j = 0; j < q; j++) {
			scanf("%d", &tmp);
			id[i] += pow(2, tmp-1);
		}
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans = 0;
		for (int j = 0; j < n; j++) {
			if ((id[i]&tim[j])==tim[j])
				ans++;
		}

		printf("%d\n", ans);
	}


	return 0;
}