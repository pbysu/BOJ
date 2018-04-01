#include<cstdio>
#include<cstring>
using namespace std;
struct Trie {
	Trie * num[10];
	bool terminate, exisist;
	Trie() {
		memset(num, 0, sizeof(num));
		terminate = exisist = false;
	}
	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (num[i])delete num[i];
		}
	}
	bool insert(const char* n) {
		if (*n == '\0') {
			terminate = true;
			return exisist;
		}
		int idx = *n - '0';
		if (!num[idx]) {
			num[idx] = new Trie;
		}
		exisist = true;
		bool flage = num[idx]->insert(n + 1);
		return terminate || flage;
	}
};
int t, n;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		Trie *root = new Trie;
		bool res = true;
		for (int i = 0; i < n; i++)
		{
			char num[11];
			scanf("%s", &num);
			if (res && root->insert(num)) {
				res = false;
			}
		}
		if (res)
			printf("YES");
		else
			printf("NO");
		printf("\n");
		delete root;
	}
	return 0;
}