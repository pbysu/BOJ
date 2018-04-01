#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n;
int alp[27];
char str[101];
int main() {
	scanf("%s", &str);
	memset(alp, -1, sizeof(alp));
	for (int i = 0; i < strlen(str); i++) {
		if (alp[str[i] - 'a'] == -1)
			alp[str[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", alp[i]);
	}
	return 0;
}