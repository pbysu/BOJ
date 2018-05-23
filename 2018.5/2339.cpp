#include<iostream>
#include<cstring>
#include<vector>
#define val 17
using namespace std;
typedef long long ll;
const ll mod =(1e13) + 1;
char a[1000010], b[1000010];
int ans = 0;
ll power = 1;
vector<int> v;
inline ll getKey(char s[], int siz) {
	ll ret = 0;
	for (int i = 0; i < siz; i++)
		ret = (ret*val + (s[i]))%mod;
	return ret;
}
int main() {
	scanf("%[^\n]", a);
	getchar();
	scanf("%[^\n]", b);
	int siz = strlen(b);
	int tsiz = strlen(a);
	if (siz > tsiz) {
		printf("0\n");
		return 0;
	}
	ll key = getKey(b,siz);
	ll tkey = getKey(a, siz);
	if (key == tkey)ans++, v.push_back(1);
	
	for (int i = 1; i < siz; i++) {
		power = (power*val) % mod;
	}
	for (int i = 1; i+siz-1 < tsiz; i++) {
		tkey = (tkey - power*a[i - 1]%mod + mod) % mod;
		tkey = (tkey*val + a[i + siz-1])%mod;
		if (tkey == key)
			ans++, v.push_back(i+1);
	}
	printf("%d\n", ans);
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}