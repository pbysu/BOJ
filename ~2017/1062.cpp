#include<iostream>
#include <string>
#include<algorithm>

using namespace std;
typedef long long ll;
int N, K;
string input[50];
ll szSave[50];
ll base;
int idx = 0;
int func(int cnt, int lastAlpa, ll nowBit) {
	if (cnt > K || lastAlpa > 25) return 0;
	int ret = 0;

	for (int i = 0; i < idx; i++) {
		if ((szSave[i] & nowBit) == szSave[i]) {
			ret++;
		}
	}
	for (int i = lastAlpa+1; i <= 26; i++) {
		if (((1 << i) & nowBit) == (1 << i)) continue;
		ret = max(func(cnt + 1, i, (nowBit|(1 << i))), ret);
	}
	return ret;
}
int main() {
	scanf("%d %d", &N, &K);
	K -= 5;
	if (K < 0) {
		printf("0\n");
		return 0;
	}
	idx = 0;
	string tmp;
	base |= 1 << ('a' - 'a');
	base |= 1 << ('n' - 'a');
	base |= 1 << ('t' - 'a');
	base |= 1 << ('i' - 'a');
	base |= 1 << ('c' - 'a');
	
	for (int sz, i = 0; i < N; i++) {
		cin >> tmp;
		sz = tmp.size();
		if (sz >= 8 && tmp.substr(0, 4) == "anta" && tmp.substr(sz - 4, 4) == "tica") {
			tmp = tmp.substr(4, sz - 4 - 4);
			for (int j = 0; j < tmp.size(); j++) {
				szSave[idx] |= (1 << (tmp[j] - 'a'));
			}
			szSave[idx++]|=base;
		}
	}

	printf("%d\n", func(0, 0, base));

	return 0;
}