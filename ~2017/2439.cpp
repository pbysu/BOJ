#include<iostream>

using namespace std;

int main() {
	int flo,temp;
	cin >> flo;
	temp = flo;

	for (int i = 1; i < flo+1; i++) {

		for (int j = 0; j < temp-1; j++) {
			cout << " ";

		}
		temp--;
		for (int k = 0; k < i; k++) {
			cout << "*";
		}
		cout << "\n";
	}

}