#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	int temp = 0;
	int j;
	for (int i = 1; i <= num; i++) {
		temp = 0;
		j = i;
		while (j != 0) {
			temp += j% 10;
			j=j / 10;
		}
		temp += i;
		if (temp == num) {
			printf("%d", i);
			break;
		}
		if (i == num) {
			printf("%d", 0);
		}
	}
	
	return 0;
}