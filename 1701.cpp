#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int pi[5010];
string b;

void getPi() {
	int j = 0;
	for (int i = 1; i < b.size(); i++) {
		while (j > 0 && b[i] != b[j])
			j = pi[j - 1];        //불일치가 일어날 경우
		if (b[i] == b[j])
			pi[i] = ++j;        //prefix가 같은 가중치만큼 pi를 정해줍니다.
	}
}


int main() {
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
			b = str.substr(i,str.size()-i);
			getPi();
			for (int k = 0; k < b.size(); k++) {
				ans = max(ans, pi[k]);
			}
			memset(pi, 0, sizeof(pi));
	}
	printf("%d", ans);
	return 0;
}