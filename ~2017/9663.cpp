#include <cstdio>
int solve(int L, int R, int M)
{
	if (M == 0) return 1;
	int ans = 0;
	int x = L&R&M;
	while (x)
	{
		int lb = x&-x;
		ans += solve(((L&~lb) << 1) | 1, (R&~lb) >> 1, M&~lb);
		x -= lb;
	}
	return ans;
}

int main()
{
	int N;
	scanf("%d", &N);
	printf("%d\n", solve(~0, ~0, (1 << N) - 1));
}