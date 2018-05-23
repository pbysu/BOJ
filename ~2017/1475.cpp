#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string room;
	int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
	cin >> room;
	for (int i = 0; i < room.length(); i++) {
		for (int j = 0; j<10; j++) {
			if (room[i]-'0' == j) arr[j]++;
		}
	}
	if ((arr[6] + arr[9] )% 2 == 0) {
		arr[6] = (arr[6] + arr[9]) / 2;
	}
	else arr[6] = ((arr[6] + arr[9]) / 2) + 1;

	sort(arr, arr + 8);
	reverse(arr, arr + 8);
	cout << arr[0];
}