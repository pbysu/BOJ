#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int x;
	int a = 0;
	s[0] = s[0] - '0';
	x = s[0] / 4;
	s[0] = s[0] % 4;
	if (x != 0) {
		printf("%d", x);
		a = 1;
	}

	x = s[0] / 2;
	s[0] = s[0] % 2;
	if(x!=0||a==1)
		printf("%d", x);
	printf("%d", s[0]);
	for (int i = 1; i < s.length(); i++) {
		s[i] = s[i] - '0';
		x = s[i] / 4;
		s[i] = s[i] % 4;
		printf("%d", x);
		x = s[i] / 2;
		s[i] = s[i] % 2;
		printf("%d", x);
		printf("%d", s[i]);

	}
}