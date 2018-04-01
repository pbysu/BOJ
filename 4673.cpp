#include<iostream>
using namespace std;
bool self[10001];
void func(int num) {
	if (num > 10000)
		return;
	if (!self[num]) {
		self[num] = true;
		int x = num;
		while (num > 0) {
			x += num % 10;
			num /= 10;
		}
		return func(x);
	}
}
int main() {

	for (int i = 1; i <= 10000; i++) {
		if (self[i] == false) {
			func(i);
			printf("%d\n", i);
		}
	}
	return 0;
}