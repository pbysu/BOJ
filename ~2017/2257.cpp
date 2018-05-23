#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
char in[10001];
int ans;
map<char, int>m;
int idx ,sz;
int func(int cur) {
	int ret=0;
	while (idx != sz) {
		if (in[idx] == '(') {
			ret += func(++idx);
		}
		else if (in[idx] >= 'A'&&in[idx] <= 'Z') {
			if (in[idx + 1] >= '0'&&in[idx + 1] <= '9') {
				ret += m[in[idx]] * (in[idx+1] - '0');
				idx += 2;
			}
			else {
				ret += m[in[idx]];
				idx += 1;
			}
		}
		else if (in[idx] == ')') {
			if (in[idx + 1] >= '0'&&in[idx + 1] <= '9') {
				ret = ret * (in[idx+1] - '0');
				idx += 2;
			}
			else {
				idx++;
			}
			return ret;
		}
		else if (in[idx] == '\0')
			return ret;
	}
	return ret;
}
int main() {
	m['H'] = 1;m['O'] = 16;m['C'] = 12;
	scanf("%s", &in);
	sz = strlen(in);
	ans =func(0);
	printf("%d\n", ans);
	return 0;
}