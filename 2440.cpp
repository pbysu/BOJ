#include<iostream>

using namespace std;

int main() {
	int flo;
	cin >> flo;
	int k = flo;

	for (int i = 1; i < flo + 1; i++) {

		for (int j = 0; j < k; j++) {
			cout << "*";
		}
		k--;
		cout << "\n";
	}

}