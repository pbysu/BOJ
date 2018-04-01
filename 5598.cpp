#include<iostream>
#include<cstring>
using namespace std;
char str[1010];
int main() {
	scanf("%s", &str);
	for (int i = 0; i < strlen(str); i++) {
		printf("%c", (str[i]-'A'-3+26) % 26+'A');
	}

	return 0;
}