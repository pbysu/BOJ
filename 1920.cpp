#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int n;
int main() {
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	scanf("%d", &n);
	sort(v.begin(), v.end());
	for (int tmp, i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (binary_search(v.begin(), v.end(),tmp)) printf("1\n");
		else printf("0\n");
	}
}