#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
using namespace std;
bool arr[1000001];
int main() {
	arr[0] = true;
	arr[1] = true;
    arr[1000000]=true;
	int st, en;
	scanf("%d %d", &st, &en);

	for (int i = 2; i <= 1000; i++) {
		for (int j = i+1; j <= en; j++) {
			if (arr[j] == false ) {
				if (j % i == 0) {
					arr[j] = true;
				}
			}
		}
	}

	for (int i = st; i <= en; i++) {
		if (arr[i] == false) {
			printf("%d\n", i);
		}
	}
}