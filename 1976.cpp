#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
vector<int> p;
vector<int> siz;

int find(int n) {
	if (n ==p[n] )
		return  n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	b= find(b);
	if (a == b)
		return;

	if (siz[a] > siz[b])
		swap(a, b);
	p[b] = a;
	siz[a] ++;
}

int main() {
	scanf("%d", &n);
	p.resize(n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	siz.resize(n, 0);
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		for (int temp, j = 0; j < n; j++) {
			scanf("%d", &temp);
			if (i < j&&temp == 1)
				merge(i, j);
		}
	}
	int ex, pos;
	scanf("%d", &ex);
	ex = find(ex-1);

	for (int temp, i = 1; i < m; i++) {
		scanf("%d", &temp);
		pos = find(temp-1);
		if (ex != pos)return  printf("NO\n"), 0;
	}
	printf("YES\n");

	return 0;
}