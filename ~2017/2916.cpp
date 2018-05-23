#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
int n, m;
int dp[370];
vector<int> input;
vector<int> problem;
void func(int cur) {
	if (cur < 0) cur += 360;
	if (cur > 360) cur -= 360;
	if (dp[cur] == true)
		return;
	dp[cur] = true;
	for (int i = 0; i < input.size(); i++) {
		func(cur + input[i]);
		func(cur - input[i]);
	}
	return;
}
int main() {
	scanf("%d %d", &n, &m);
	input.resize(n);
	problem.resize(m);
	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);
	for (int i = 0; i < m; i++) 
		scanf("%d", &problem[i]);
	func(0);

	for (int i = 0; i < m; i++) {
		if (dp[problem[i]] == true) {
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}