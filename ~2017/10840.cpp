#include<cstdio>
#include<cstring>
#include<set>
#include<iostream>
#include<vector>	
#include<string>
#include<algorithm>
using namespace std;
string str, str1;
vector<int> v;
set<vector<int>>s;
int lo, hi;
int main() {
	cin >> str >> str1;

	for(int i=1; i<= str.length(); i++){
		v.assign(26,0);
		lo = hi = 0;
		while (hi < str.length()) {
			if (hi - lo < i) {
				v[str[hi] - 'a']++;
				hi++;
			}
			else {
				s.insert(v);
				v[str[hi] - 'a']++;
				v[str[lo] - 'a']--;
				hi++, lo++;
			}
		}
		s.insert(v);
	}
	int ans = 0;
	for (int i = 1; i<= str1.length(); i++) {
		v.assign(26,0);
		lo = hi = 0;
		while (hi < str1.length()) {
			if (hi - lo < i) {
				v[str1[hi] - 'a']++;
				hi++;
			}
			else {
				if (s.count(v)) ans = max(ans, i);
				v[str1[hi] - 'a']++;
				v[str1[lo] - 'a']--;
				hi++, lo++;
			}
		}
		if (s.count(v)) ans = max(ans, i);
	}
	printf("%d\n", ans);
	return 0;
}