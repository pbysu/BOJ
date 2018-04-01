#include <iostream>
#include <string>

using namespace std;
bool alpa[26];


int main() {

	int tc;
	scanf("%d", &tc);
	for (int j = 0; j < tc; j++) {
		for (int i = 0; i < 26; i++)alpa[i] = false;
		string test;
		cin >> test;
		int total = 0;
		int size = test.length();
		for (int i = 0; i < size; i++) {
			if (alpa[test[i] - 65] == false) {
				alpa[test[i] - 65] = true;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (alpa[i] == false) {
				total += i + 65;
			}
		}
		printf("%d\n", total);
	}

	return 0;
}