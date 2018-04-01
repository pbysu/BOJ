#include <iostream>
using namespace std;

int main() {

	int i = 0;
	int j;
	cin >> j;
	int *p = new int[j];

	while (i < j) {
		int a, b;
		char c;
        scanf("%d, %d",&a,&b);
		p[i] = a + b;
		i++;
	}

	i = 0;
	while (i < j) {
		cout << p[i] << endl;
		i++;
	}

}