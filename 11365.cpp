#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main() {
	string a;
	getline(cin, a);
	while ( a!= "END") {
		for (int i = a.length() - 1; i >= 0; i--) {
			printf("%c", a[i]);
		}
		printf("\n");
		getline(cin, a);
	}

	return 0;
}