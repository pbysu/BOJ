#include<iostream>
#include<string>
using namespace std;

char arr[101];
int main() {
	string a;
	cin >> a;
	int size = a.length();
	for (int i = 0; i < size; i++) {
		if (a[i] / 'a' != 0) {
			a[i] = a[i]%'a'+'A';
		}
		else
			a[i] = a[i]%'A' + 'a';
	}
	cout << a;
	return 0;
}