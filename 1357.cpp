#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char one[6];
char two[6];
int main() {
	scanf("%s %s", &one, &two);
	one[strlen(one)] = '\n';
	two[strlen(two)] = '\n';
	int ans = 0;
	int k = 1;
	for (int i = 0; i < strlen(one)-1; i++) {
		ans += (one[i]-'0' )* (k);
		k *= 10;
	}
	k = 1;
	for (int i = 0; i < strlen(two)-1; i++) {
		ans += (two[i] - '0' ) * k;
		k *= 10;
	}
	bool tmp = false;
	while (ans > 0) {
		if (ans % 10 == 0) {
			if (tmp) {
				printf("0");
			}
		}
		else {
			tmp = true;
			printf("%d", ans%10);
		}
		ans/=10;
	}
	return 0;
}