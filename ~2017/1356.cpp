#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
char num[10];
long long frontbit = 1;
long long backbit = 1;
int main() {
	scanf("%s", &num);
	bool ret = 0;
	for (int i = 1; i < strlen(num); i++) {
		for (int k = 0; k < i; k++) {
			frontbit *= (num[k] - '0');
		}
		for (int k = i; k < strlen(num); k++) {
			backbit *= (num[k] - '0');
		}
		if (frontbit == backbit) {
			ret = true;
		}
		backbit = 1;
		frontbit = 1;
	}
	if (ret) {
		printf("YES");
	}
	else
		printf("NO");

	return 0;
}