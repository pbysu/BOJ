#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<iostream>
#include<string>
#include<algorithm>

using std::cin;
using std::printf;
using std::sort;
using std::scanf;
using std::string;

char arr[10];

bool compare(char p1, char p2) {
	return  p1-'0' > p2-'0';
}

int main (){
	scanf("%s", arr);
	sort(arr, arr + sizeof(arr) / sizeof(char), compare);
	printf("%s", arr);
}