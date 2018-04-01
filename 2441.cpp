#include<iostream>

using namespace std;

int main() {
	int flo;
	cin >> flo;
	int k = flo;

	for (int i = 0; i < flo; i++) {
		for (int m = 0; m < i; m++) {
			cout << " ";
		}
		for (int j = 0; j < k; j++) {
			cout << "*";
		}
		k--;
		cout << "\n";
	}

}