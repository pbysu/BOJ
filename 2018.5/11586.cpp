#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> v;
int n, cas;
int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> cas;
	if (cas == 1) {
		for (int i = 0; i < n; i++) {
			cout << v[i];
			printf("\n");
		}
	}
	else if (cas == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				cout << v[i][j];
			}
			printf("\n");
		}
	}
	else {
		for (int i = n-1; i >= 0; i--) {
			cout << v[i];
			printf("\n");
		}
	}
	return 0;
}