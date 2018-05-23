#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str;
string rev;

int main() {
	cin >> rev;
	str = rev;
	bool zer = true;
	for (int i = 0; i < rev.size() / 2; i++) {
		if (rev[i] != rev[rev.size() - 1 - i]) {
			zer = false;
			break;
		}
	}
	if (zer)
		printf("%d", rev.size());
	else {
		reverse(rev.begin(), rev.end());
		int ans;
		for (int i = 0; i < str.size(); i++) {
			bool jd = true;
			for (int j = 0; i + j < str.size(); j++) {
				if (rev[j] != str[i + j]) {
					jd = false;
					break;
				}
			}

			if (jd == true) {
				ans = i + str.size();
				break;
			}
		}
		printf("%d", ans);
	}

	return 0;
}