#include<iostream>
using namespace std;


int main() {
	int i=0, j,k;
	cin >> j;
	k = j-1;
	while (i < j) {
		cout << j-k << "\n";
		k--;
		i++;
	}
}