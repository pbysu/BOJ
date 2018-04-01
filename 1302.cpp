#include<iostream>
#include<string>
#include<map>

using namespace std;
map <string, int>cmp;
int main() {
	int tc;
	scanf("%d", &tc);
	string temp;
	for (int i = 0; i < tc; i++) {
		cin >> temp;
		cmp[temp]++;
	}

	map<string, int>::iterator it = cmp.begin();
	map<string, int>::iterator te = cmp.begin();
	for (it; it != cmp.end(); it++) {
		if (te->second < it->second) te = it;
	}

	cout << te->first;
}