#include<iostream>

using namespace std;

int main() {
	int flo;
	cin >> flo;
	int time=flo,temp = flo;
	

	for (int i = 1; i < flo + 1; i++) {
		for (int m = 0; m < time - 1; m++) {
			cout << " ";
		}
		time = time - 1;

		for (int j = 0; j < 2 * i - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	int k = 0;

	for (int i =2; i < flo + 1; i++){

		for (int m = 0; m < k+1; m++) {
			cout << " ";
		}
		k = k + 1;

		for (int j = 0; j <= 2*temp-2-2; j++) {
			cout << "*";
		}
		temp--;
		cout << "\n";
	}

}