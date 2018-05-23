#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main()
{
	string arr;
	cin >> arr;
	int total = 10;
	int end = arr.length() - 1;
	for (int i = 0; i <end; i++) {
		if (arr[i] == arr[i + 1]) {
			total += 5;
		}
		else
		{
			total += 10;
		}
	}
	printf("%d", total);
}