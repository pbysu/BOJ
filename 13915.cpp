#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
int t;
int cnt = 0;
string str;
int main() {
	while (scanf("%d",&t)!=EOF) {
		cnt = 0;
		vector<set<char>> v;
		v.resize(t);
		for (int i = 0; i< t; i++) {
			cin >> str;
			for (int j = 0;j<str.size();j++) {
				v[i].insert(str[j]);
			}
		}
		sort(v.begin(), v.end());
		cnt = unique(v.begin(), v.end()) - v.begin();
		printf("%d\n", cnt);
	}

	return 0;
}