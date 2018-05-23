#include <iostream>
using namespace std;

char p[100];
int main() {
	int i=0, j;
	cin >> j;

	cin >> p;
	int total = 0;
	while (i < j) {
		total += p[i]-48;
		i++;
	}

	cout << total;
}