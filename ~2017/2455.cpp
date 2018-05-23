#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
using namespace std;
int arr[5];
int main() {
	int a; int b;
	arr[0] = 0;
	int max=0;
	for (int i = 1; i < 5; i++) 
	{
		scanf("%d %d", &a, &b);
		arr[i] = arr[i - 1] + b-a;
		max = max < arr[i] ? arr[i] : max;
	}
	printf("%d", max);
}