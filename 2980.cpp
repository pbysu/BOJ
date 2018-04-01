#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
int n, m, cnt, len, u, v, c, pos, total;
int main() {
	scanf("%d %d", &n, &len);
	pos = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &u, &v, &c);
		total = v + c; cnt += u - pos;
		int tmpCnt = cnt%total;
		pos = u;
		if (/*tmpCnt == 0 ||*/ tmpCnt - v > 0)
		{continue;	}
		cnt += v - tmpCnt;
	}

	printf("%d", cnt+(len-pos));

	return 0;
}