#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
vector<int> a;
vector<int>b;
int main() {
	int n;
	scanf("%d", &n);
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	int ret = 0; 
	for (int i = 0; i < n; i++) {
		ret += a[i] * b[i];
	}
	printf("%d", ret);
	return 0;
}