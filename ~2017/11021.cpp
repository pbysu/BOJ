#include <iostream>
using namespace std;

int main() {

	int i = 0;
	int j;
	cin >> j;
	int *p = new int[j];

	while (i < j) {
		int a, b;
		cin >> a;
		cin >> b;
		p[i] = a + b;
		i++;
	}

	i = 0;
	while (i < j) {
		cout <<"Case #"<<i+1<<": "<< p[i] << endl;
		i++;
	}

}