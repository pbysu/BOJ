#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> in;
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	in.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	sort(in.begin(), in.end());
	for (int s, e, i = 0; i < m; i++) {
		scanf("%d %d", &s, &e);
		int sidx = lower_bound(in.begin(), in.end(), s) - in.begin();
		int eidx = upper_bound(in.begin(), in.end(), e) - in.begin();
		if (eidx >= 0 && sidx < in.size() || eidx <= in.size()) {
			printf("%d", eidx - sidx);
		}
		else
			printf("0");
		printf("\n");
	}
	return 0;
}