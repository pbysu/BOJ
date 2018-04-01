#include<iostream>
#include<algorithm>
#define INF 987654321

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	int tmp;
	int ans = 0;
	int remember = -1*INF;

	while (tc--) {
		scanf("%d", &tmp);

		remember = max(tmp, remember);

		if (tmp < 0) {
			if (ans + tmp >0)
				ans = ans + tmp;
			else {
				ans = 0;
			}
		}

		else {
			ans = ans + tmp;
			remember = max(ans, remember);
		}
	}

	printf("%d", remember);

	return 0;
}