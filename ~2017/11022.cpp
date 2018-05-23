#include <iostream>
using namespace std;

int main() {

	int i = 0;
	int j;
	cin >> j;
	int *p = new int[j];
	int *a = new int[j];
	int *b = new int[j];

	while (i < j) {
		cin >> a[i];
		cin >> b[i];
		p[i] = a[i] + b[i];
		i++;
	}

	i = 0;
	while (i < j) {
		cout <<"Case #"<<i+1<<": "
			<< a[i]<<" + "<<b[i]<<" = "<< p[i] << endl;
		i++;
	}
	delete a;
	delete b;
	delete p;
}