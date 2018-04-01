#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> v;
int n, tmp;
int main() {
	scanf("%d", &n);
	v.resize(n+1);
	scanf("%lld", &v[1]);
	for(int i =2; i<= n; i++){
		scanf("%lld", &v[i]);
		v[i] += v[i - 1];
	}
	scanf("%d", &tmp);
	for (int s,e, i = 0; i < tmp; i++){
		scanf("%d %d", &s, &e);
		printf("%lld\n", v[e] - v[s - 1]);
	}
	return 0;
}