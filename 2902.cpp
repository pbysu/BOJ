#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string name;
	char arr[102];
	cin >> name;
	int num = 1;
	arr[0] = name[0];
	for (int i = 1; i < name.length(); i++) {
		if (name[i] == '-') {
			arr[num] = name[i + 1];
			num++;
		}
	}
	for (int i = 0; i < num; i++) {
		cout << arr[i];
	}

}