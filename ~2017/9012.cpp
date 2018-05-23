#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char>st;

int main() {
	string a;
	int tc;
	scanf("%d", &tc);
	char tp;
	int cus, cue;
	int jd = 0;

	for (int i = 0; i < tc; i++) {

		while (!st.empty())
			st.pop();

		cus = cue = 0;
		jd = 0;
		cin >> a;

		for (int i = 0; i < a.length(); i++) {
			st.push(a[i]);
		}

		if (st.empty()) {
			printf("NO\n");
			jd = 1;
			continue;
		}
		if (st.size() % 2 != 0) {
			printf("NO\n");
			jd = 1;
			continue;
		}

		if (st.top() != ')') {
			printf("NO\n");
			jd = 1;
			continue;
		}
		int size = st.size();

		for (int i = 0; i < size; i++) {
			if (st.top() == ')')
				cus++;
			else
				cus--;

			if (cus < 0) {
				printf("NO\n");
				jd = 1;
				break;
			}

			st.pop();
			if (st.size() == 0) {
				break;
			}
			if (st.size() == 1) {
				if (st.top() != '(') {
					printf("NO\n");
					jd = 1;
					break;
				}
			}
		}
		if (jd != 1) {
			if (cus == 0) {
				printf("YES\n");
			}
			else
				printf("NO\n");
		}
	}

	return 0;
}