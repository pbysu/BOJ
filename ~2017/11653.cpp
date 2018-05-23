#include <iostream>
#include <stdio.h>
#include<math.h>
using namespace std;

int num1 = 2;

int sosu(int num,int temp) {
	if (num < temp) {
		return true;
	}
	if (num%temp == 0) {
		cout << temp << endl;
		num = num / temp;
		return sosu(num,temp);
	}
	else {
		temp++;
		return sosu(num, temp);
	}
}
int main() {
	int num1;
	cin >> num1;
	sosu(num1, 2);
}