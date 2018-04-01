#include<iostream>
#include<algorithm>
using namespace std;


int input[310];
int dp[3][310];
int n;

int func(int pos, int cnt) {

	if (pos < 0)
		return 0;

	int &ret = dp[cnt][pos];

	if (ret != 0)
		return ret;

	if (cnt == 0) {
		ret = func(pos - 1, 1) + input[pos];
		return ret;
	}

	if (cnt == 1)
		return ret = max(func(pos - 1, 0), func(pos - 1, 2));

	else {
		if (pos < 1) return 0;
		ret = func(pos - 2, 1) + input[pos - 1] + input[pos];
		return ret;
	}


}

int main() {


	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
	printf("%d", max(func(n - 1, 2), func(n - 1, 0)));
	return 0;
}