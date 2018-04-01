#include<iostream>
#include<algorithm>

using namespace std;
int arr[1000000];

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, &arr[t]);

	for (int i = 0; i < t; i++) {
		cout << arr[i] <<"\n";
	}

}