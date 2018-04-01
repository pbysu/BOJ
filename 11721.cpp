#include<iostream>
using namespace std;
char arr[100];

int main() {
	cin >> arr;
	int i = 0, k = 1;
	while (arr[i] != 0) {
		if (i == (10 * k)) {
			cout << "\n";
			k++;
		}
		cout << arr[i];
		i++;

	}
}