#include<iostream>
#include<cstring>
using namespace std;
char str[1000];
char str1[1000];
int cnt[26];
int main() {
	scanf("%s", &str);
	scanf("\n%s", &str1);
	for (int i = 0; i < strlen(str); i++) {
		cnt[str[i] - 'a']++;
	}
	int ans = 0;
	for (int i = 0; i < strlen(str1); i++) {
		cnt[str1[i] - 'a']>0? cnt[str1[i]-'a']--: ans++;
	}
	for (int i = 0; i < 26; i++) {
		ans += cnt[i];
	}
	printf("%d", ans);
	return 0;
}