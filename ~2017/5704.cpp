#include <iostream>
#include <string>

using namespace std;

bool n[26];

int main() {
	string st;
	while (1) {
		getline(cin, st);
		int jd = 0;
		if (st == "*") break;
		int size = st.length();
		for (int i = 0; i < size; i++) {
			n[st[i] - 'a'] = true;
		}
		for (int i = 0; i < 26; i++) {
			if (n[i] == false) {
				jd = 1;
				break;
			}
		}
		if (jd == 0) printf("Y\n");
		else printf("N\n");
		for (int i = 0; i < 26; i++) {
			n[i] = false;
		}
	}
	return 0;
}