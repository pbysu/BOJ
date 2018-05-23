#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int num[10000];
int total = 0;
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		total += str[i] - '0';
	}
	sort(str.begin(), str.end());
	reverse(str.begin(), str.end());

	if (str[str.length()-1] != '0' || total%3!=0)
		printf("-1");
	 
	else
	cout << str;
	return 0;
}