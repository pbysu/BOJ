#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct POS {
	int x, y;
	POS(int x, int y) :x(x), y(y) {}
};
int check(POS a, POS b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
int n, u, v, a, b;
vector<POS>pos;
vector<int> c;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &u, &v);
		pos.emplace_back(u, v);
	}
	int len = 0;
	int tlen;
	int mt = 0;
	for (int i = 1; i < n - 1; i++) {
		tlen = check(pos[i - 1], pos[i + 1]);
		a = check(pos[i - 1], pos[i]);
		b = check(pos[i], pos[i + 1]);
		mt = max(mt, a + b - tlen);
		len += a;
		if(i==n-2) len += b;
	}
	printf("%d", len - mt);
	return 0;
}