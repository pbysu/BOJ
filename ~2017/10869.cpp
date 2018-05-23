#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>

using namespace std;
int main() {
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	printf("%d\n%d\n%d\n%d\n%d\n", n1 + n2,n1-n2,n1*n2,n1/n2,n1%n2);

}