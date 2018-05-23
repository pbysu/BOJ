#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main() {
	string a;
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> a;
		printf("%c%c\n", a[0], a[a.length() - 1]);

	}
	return 0;
}