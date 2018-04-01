#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int alpa[26];
int main() {
	string a;
	cin >> a;
	int size = a.length();
	
	for (int i = 0; i < size; i++) {
		alpa[a[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++){
		printf("%d ", alpa[i]);
}

	return 0;
}