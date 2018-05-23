#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int n, k;
int main() {
	scanf("%d %d", &n, &k);
	v.resize(n);
	int m = n - 1;
	for (int i = 0; i < m; i++) {
		scanf("%d,", &v[i]);
	}
	scanf("%d", &v[n - 1]);
	int p = 0;;
	while (p != k) {
		vector<int> tmp;

		tmp.resize(m);
		for (int i = 0; i < m; i++) {
			tmp[i] = v[i + 1] - v[i];
		}
		v.clear();
		v = tmp;
		m--;
		p++;
	}

	for (int i = 0; i < n - k-1; i++) {
		printf("%d,", v[i]);
	}
	printf("%d", v[n - k - 1]);


	return 0;
}