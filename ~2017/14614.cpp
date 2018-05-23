#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int a, b;
string str;
int main() {
	cin >> a >> b >> str;

	if ((str[str.size()-1]-'0')%2==0) {
		cout << a;
	}
	else cout << (a^b);
	return 0;
}