#include<iostream>

using namespace std;

int main() {

	int s;
	scanf("%d", &s);
	if (s >= 90) { printf("A"); return 0; }
	else if(s>=80) { printf("B"); return 0; }
	else if (s >= 70) { printf("C"); return 0; }
	else if (s >= 60) { printf("D"); return 0; }
	else printf("F");
	return 0;
}