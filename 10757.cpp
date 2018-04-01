#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

int main() {
	string a;
	string b;
	cin >> a;
	cin >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string ans;
	int up = 0;

	if (a.length() >= b.length()) {
		ans = a;
		up = 0;
		int temp = 0;
		for (int i = 0; i < b.length(); i++) {
			temp = a[i] - '0' + b[i] - '0' + up;
			up = temp / 10;
			ans[i] = temp % 10 +'0';
		}
		for (int i = b.length(); i < a.length(); i++) {
			temp = a[i] - '0' + up;
			up = temp / 10;
			ans[i] = temp % 10 +'0';
		}
	}
	else {
		ans = b;
		up = 0;
		int temp = 0;
		for (int i = 0; i < a.length(); i++) {
			temp = a[i] - '0' + b[i] - '0' + up;
			up = temp / 10;
			ans[i] = temp % 10 +'0';
		}
		for (int i = a.length(); i < b.length(); i++) {
			temp = b[i] - '0' + up;
			up = temp / 10;
			ans[i] = temp % 10 +'0';
		}
	}

	reverse(ans.begin(), ans.end());
	if (up == 1) {
		printf("1");
	}
	cout << ans << endl;

	return 0;
}