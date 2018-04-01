#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string arr[500000];
string arr1[500000];


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr1[i];
	}
	sort(arr, arr + n);
	int check = 0;
	for (int i = 0; i < m; i++) {
		if (binary_search(arr, arr + n, arr1[i])) {
			arr1[check] = arr1[i];
			check++;
		}
	}
	printf("%d\n", check);
	sort(arr1, arr1 + check);
	for (int i = 0; i < check; i++) {
		cout << arr1[i];
		printf("\n");
	}
}