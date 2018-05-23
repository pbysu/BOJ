#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
char arr[101];
int main() {
	int tc;
	scanf("%d", &tc);
	scanf("%c", &arr[0]);
	for (int k = 0; k < tc; k++){
	string a;
	getline(cin, a);
	if(a[0]/'a'==1){
	a[0] = a[0] % 'a' + 'A';
	}
	cout << a<<endl;
	}
	return 0;
}