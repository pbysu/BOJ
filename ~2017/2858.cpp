#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int r, b, p, q;
	scanf("%d%d", &r, &b);
	for (int i = 1; i <= 5000; i++) {
		p = i;
		if (b%p == 0) {
			q = b / p;
			int t = p * 2 + q * 2 + 4;
			if (t == r)
			{

				int large = max(i + 2, q + 2);
				int small = min(i + 2, q + 2);
				printf("%d %d", large, small); break;
			}
		}

	}
	return 0;
}