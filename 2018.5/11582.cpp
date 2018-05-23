#include<cstdio>
using namespace std;
typedef long long ll;
int n, ans;
ll arr[2000010], tmp[1000010];
ll key = 0, tmpkey = 0, power = 1, mod = 1e17 + 1, val = 7;
char c;

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

inline ll getmod(ll n, ll* arr) {
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		ret = (ret*val + arr[i]) % mod;
	}
	return ret;
}

inline void getChange(ll& curKey, ll* arr, int i) {
	curKey = (curKey - power*arr[i - 1] % mod + mod) % mod;
	curKey = ((curKey*val) + arr[i + n - 1]) % mod;
}

int main() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c", &c);
		tmp[i] = ll(c);
		if (i)
			power = ll(power * val) % mod;
		getchar();
	}
	for (int i = 0; i < n; i++) {
		scanf("%c", &c);
		arr[i] = ll(c);
		arr[i + n] = arr[i];
		getchar();
	}
	arr[2 * n - 1] = 0;

	tmpkey = getmod(n, tmp);
	key = getmod(n, arr);
	bool jd = true;

	if (tmpkey == key) {
		for (int i = 0; i < n; i++) {
			if (arr[i] != tmp[i])
			{
				jd = false; break;
			}
		}
		if (jd) ans++;
	}
	ll test = 0;
	for (int i = 1; i < n; i++) {
		getChange(key, arr, i);
		if (tmpkey == key&&arr[i] == tmp[0] && arr[i + 1] == tmp[1]) {
			ans++;
		}
	}
	int t = gcd(n, ans);
	printf("%d/%d", ans / t, n / t);
	return 0;
}