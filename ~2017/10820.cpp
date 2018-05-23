#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main() {
	string a;
	int T = 0, t = 0, s = 0, n =0;
	while(getline(cin, a)){
		T = 0, t = 0, s = 0,n =0;
		
		for (int j = 0; j < a.length(); j++) {
			if (a[j] == ' ') s++;
			else if (a[j] / 'a' == 1) t++;
			else if (a[j] / 'A' == 1)T++;
			else n++;
		}
		printf("%d %d %d %d\n", t, T, n, s);
	}
	return 0;
}