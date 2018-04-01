#include <iostream>
using namespace std;

int main() {

	int t, n, m, G, L,temp,a,b;
	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> n >> m;
		temp = n;
		n = n >= m ? n : m;
		m = temp >= m ? m : temp;

		a = n, b = m;
		if (n%m == 0) {
			L = n;
			G = m;
		}

		else {
			while (n%m != 0) {
				temp = m;
				m = n%m;
				n = temp;
			}
			G = m;
			L = a / m*b / m*m;
		}
		cout << L << endl;
	}
}