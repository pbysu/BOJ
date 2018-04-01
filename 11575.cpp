#include<iostream>
#include<string>

using namespace std;

int main() {
	int t;
	string str;
	int x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			printf("%c", ((str[j] - 'A')*x + y )%26 + 'A');
		}
		printf("\n");

	}


}