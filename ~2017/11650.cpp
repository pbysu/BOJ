#include<iostream>
#include<algorithm>

using namespace std;

struct pot {
	int x, y;
};

bool compare(pot p1, pot p2) {
	if (p1.x != p2.x) {
		return p1.x < p2.x;
	}
	else {
		return p1.y < p2.y;
	}
}

pot arr[100000];

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	sort(arr, arr + t, compare);

	for (int i = 0; i < t; i++) {
		cout << arr[i].x<<' '<<arr[i].y <<"\n";
	}

}