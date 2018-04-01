#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str;
int tmp;

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> str;
		tmp = stoi(str);
		reverse(str.begin(), str.end());
		tmp += stoi(str);
		str = to_string(tmp);
		bool  jd = true;
		int cnt = str.length() / 2;
		for (int i = 0; i <cnt; i++) {
			if (str[i] != str[str.length() - 1 - i]) {
				jd = false;
				break;
			}
		}

		if (jd) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}