#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, val;
vector<int> arr;
int ans = 0;
void func(int i, int sum, bool one) {
	if (i==n &&one&&sum == val)
		ans++;
	if (i == n)
		return;
	func(i + 1, sum, one);
	sum += arr[i];
	func(i + 1, sum, true);
}
int main() {
	scanf("%d %d", &n, &val);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	func(0, 0,false);
	printf("%d", ans);
	return 0;
}