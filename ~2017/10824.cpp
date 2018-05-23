#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


int main() {


	string a[4];

	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	a[0] = a[0] + a[1];
	a[2] = a[2] + a[3];

	reverse(a[0].begin(), a[0].end());
	reverse(a[2].begin(), a[2].end());

	string strmax;
	string strmin;

	if (a[0].length() >= a[2].length()) {
		strmax = a[0];
		strmin = a[2];
	}
	else {
		strmax = a[2];
		strmin = a[0];
	}
	int up = 0, temp = 0;
	int sizeStrmin = strmin.length();
	for (int i = 0; i < sizeStrmin; i++) {
		temp = strmax[i] - '0' + strmin[i] - '0' + up;
		up = temp / 10;
		temp = temp % 10;
		strmax[i] = temp + '0';
	}
	
	for (int i = sizeStrmin; i < strmax.length(); i++) {
		temp = strmax[i] - '0' + up;
		up = temp / 10;
		temp = temp % 10;
		strmax[i] = temp + '0';
	}
	reverse(strmax.begin(), strmax.end());
	if (up == 1) {
		printf("1");
	}

	cout << strmax;

	return 0;
}