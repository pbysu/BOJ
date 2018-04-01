#include<iostream>

using namespace std;
int p[999999];
int main() {
	int time, max, min;
	cin >> time;

	for (int i = 0; i < time; i++) {
		cin >> p[i];
	}
	max = p[0];
	min = p[0];
	for (int i = 1; i < time; i++) {
		max = max >= p[i] ? max : p[i];
		min = min <= p[i] ? min : p[i];
	}
	cout << min << " " << max;
}