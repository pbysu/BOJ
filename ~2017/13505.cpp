#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Trie {
	bool end;
	bool state;
	Trie* cas[2];
	Trie() {
		end = false;
		state = false;
		cas[0] = NULL;
		cas[1] = NULL;
	}

	void insert(const char *key) {
		if (*key == '\0') {
			end = true;
			return;
		}
		int cIdx = *key - '0';

		if (cas[cIdx] == NULL) {
			cas[cIdx] = new Trie();
		}
		return cas[cIdx]->insert(key + 1);
	}

	int func(const char * key, int dep) {
		if (dep < 0)return 0;
		int pos = *key - '0';
		if (cas[(pos ^ 1)]!= NULL) {
			return (1 << dep) + cas[pos ^ 1]->func(key + 1, dep - 1);
		}
		else
			return cas[pos]->func(key + 1, dep - 1);
	}
	~Trie() {
		delete cas[0];
		delete cas[1];
	}
};
int n, num;
char bin[100001][30];
Trie *root = new Trie();
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		for (int k = 29, j = 0; j < 30; j++, k--) {
			if (((num >> j) & 1)) {
				bin[i][k] = '1';
			}
			else
				bin[i][k] = '0';
		}
		root->insert(bin[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, root->func(bin[i],29));
	}
	printf("%d\n", ans);
	return 0;
}