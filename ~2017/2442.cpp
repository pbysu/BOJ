#include<iostream>

using namespace std;

int main() {
	int flo;
	cin >> flo;
	int k = flo;

	for (int i = 1; i < flo+1; i++) {
		for (int m = 0; m < k-1; m++) {
			cout << " ";
		}
		k = k - 1;

		for (int j = 0; j < 2*i-1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

}