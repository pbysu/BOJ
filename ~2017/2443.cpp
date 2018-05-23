#include<iostream>

using namespace std;

int main() {
	int flo;
	cin >> flo;
	int temp = flo;
	int k = 0;
	for (int i =1; i < flo + 1; i++){

		for (int m = 0; m < k; m++) {
			cout << " ";
		}
		k = k + 1;

		for (int j = 0; j <= 2*temp-2; j++) {
			cout << "*";
		}
		temp--;
		cout << "\n";
	}

}