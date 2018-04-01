#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<set>	
using namespace std;
string str;
set<string>s;
int main() {
	s.insert("c=");s.insert("c-");
	s.insert("dz="); s.insert("d-"); s.insert("lj");
	s.insert("nj"); s.insert("s="); s.insert("z=");
	cin >> str;
	int ret = 0;
	for (int i = 0; i < str.size();) {
		bool jd = false;
		int j;
		for (j = 1; j <= 4 && i+j <= str.size(); j++) {
			if (s.find(str.substr(i, j)) != s.end()) {
				jd = true;
				break;
			}
		}
		if (jd == true) {
			i += j;
		}
		else
			i++;
		ret += 1;
	}
	printf("%d\n", ret);
	return 0;
}