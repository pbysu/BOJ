#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
using namespace std;
int main() {
	int jd1= 0, jd2 = 0;
	int tc;
	int bi;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		scanf("%d", &bi);
		if (bi == 1) {
			jd1++;
		}
		else
			jd2++;
	}
	if (jd1 > jd2)
		printf("Junhee is cute!");
	else
		printf("Junhee is not cute!");
}