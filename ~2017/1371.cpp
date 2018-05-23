#include<cstdio>
#include<cstring>
using namespace std;
char arr[5010];
int cnt[26];
int main() {
	//freopen("input.txt", "r", stdin);
	while (scanf("%s", arr) != EOF) {
		int siz = strlen(arr);
		int idx;
		for (int i = 0; i < siz; i++) {
			idx = arr[i] - 'a';
			cnt[idx]++;

		}
	}
	int ans = -1;
	int val = -1;
	for (int i = 0; i < 26; i++) {
		if (val < cnt[i]) {
			val = cnt[i];
		}
	}

	for (int i = 0; i < 26; i++) {
		if (val == cnt[i]) {
			printf("%c", i + 'a');
		}
	}
	return 0;
}