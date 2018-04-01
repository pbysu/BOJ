#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string arr;
	int num = 0;
	while (cin >> arr) {
		num++;
	}
	cout << num;
}