#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int tc;
string str;
string a, b;
int main() {
	scanf("%d", &tc);

	while (tc--) {
		cin >> str;
		a = "";
		b = "";
		if (str.length() % 2 != 0) {
			str = str + str;
		}

		int sizes = str.length();

		for (int i = 0; i < sizes; i++) {
			if (i % 2 == 0) {
				a += str[i];
			}
			else
				b += str[i];
		}

		cout << a << endl << b << endl;


	}

	return 0;
}