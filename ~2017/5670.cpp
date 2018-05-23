#include<cstdio>
#include<cstring>

using namespace std;

char ch[81];
struct Tri {
	bool last, exi;
	int cnt;
	Tri *next[26];
	Tri() {
		last = false;
		exi = false;
		cnt = 0;
		for (int i = 0; i < 26; i++) next[i] = 0;
	}
	~Tri() { last = false; for (int i = 0; i < 26; i++)delete next[i]; }
	void insert(char *ch) {
		if (*ch == '\0') { last = true; return; }
		int idx = *ch - 'a';
		if (!next[idx]) {
			next[idx] = new Tri;
		}
		exi = true;
		next[idx]->insert(++ch);
		next[idx]->cnt++;
	}
	int search(int dep,int ex,int tc) {
		int ret = 0;

		if (cnt != ex)
			tc += 1;
		if (last)
			ret += tc;
		if (cnt == 1)
			return tc;

		for (int i = 0; i < 26; i++) {
			if(next[i]!=0)
 				ret += next[i]->search(dep+1,cnt,tc);
		}
		return ret;
	}
};
int main() {
	Tri* tri= 0;
	int n;


	while (scanf("%d", &n) != EOF) {
		delete tri;
		tri = new Tri;
		for (int i = 0; i < n; i++) {
			scanf("%s", &ch);
			tri->insert(ch);
		}
		printf("%.2lf\n",(double)tri->search(0,0,0)/n);
	}
	return 0;
}