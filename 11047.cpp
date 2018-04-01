#include<iostream>	
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
vector<int> v;

int func(int wone, int idx) {
	int ret = 0;
	if (wone == 0)
		return 0;
	if (wone >= v[idx])
		return wone/v[idx] + func(wone %v[idx], idx);
	else
		return func(wone, idx - 1);
}
int main() {
	scanf("%d %d", &n, &k);
	for (int temp, i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (temp < k) {
			v.push_back(temp);
		}
	}

	printf("%d", func(k,v.size()-1));
	return 0;
}