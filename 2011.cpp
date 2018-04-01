#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
char num[5000];
int input[2][5002];


void func(int pos) {
	if (input[0][pos]!=0)
		input[0][pos] = (input[0][pos - 1] + input[1][pos - 1])% 1000000;

	if(pos>1 && input[1][pos]!=0)
		input[1][pos] = (input[1][pos - 2] + input[0][pos - 2]) % 1000000;
	
}

int main() {
	scanf("%s", &num);

	int siz =strlen(num);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < siz; j++) {
			if (num[j] - '0' > 0)
				input[0][j] = 1;

			if (j!=0 && (num[j - 1] - '0') * 10 + num[j] - '0'>9 && (num[j - 1] - '0') * 10 + num[j] - '0' <27)
				input[1][j] = 1;
		}
	}

	for (int i = 1; i < siz; i++) {
		func(i);
	}
	printf("%d", (input[0][siz - 1] + input[1][siz - 1]) % 1000000);
	return 0;
}