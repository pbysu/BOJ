#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int t;
	string str;
	string str1;
	int zero;
	int one;
	scanf("%d", &t);

	while (t--) {
		zero = 0;
		one = 0;
		cin >> str;
		cin >> str1;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != str1[i]) {
				if (str[i] == '0')zero++;
				else one++;
			}
		}

		int ma = max(zero, one);
		int mi = min(zero, one);

		printf("%d\n", mi + ma - mi);
	}


}