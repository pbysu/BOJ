#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
int n, k;
map<int, int> ma;
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		if (n%i == 0) {
			ma[i]++;
			n = n / i;
			i = 1;
		}
	}
	int x = 0;
	for (auto it = ma.begin(); it != ma.end(); it++) {
		x += it->second;
	}
	int cnt = 0;
	while (x> 1) {
		cnt++;
		if (x % 2)x++;
		x /= 2;
	}
	printf("%d", cnt);
	return 0;
}