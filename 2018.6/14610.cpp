#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n, m, tmp;
int userCnt[101], problemSolve[12], cnt, start[101];
bool jd = true;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &userCnt[i]);
		if (userCnt[i] == m||userCnt[i]==0)
			jd = false;
		for (int j = 1; j <= m; j++) {
			scanf("%d", &tmp);
			if (tmp == -1 && start[i] == 0)start[i] = j;
			if (tmp == 1)
				userCnt[i]--, problemSolve[j]++;
		}
	}
	if (!jd) {
		printf("NO\n"); return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = start[i]; j <= m; j++) {
			if (userCnt[i] == 0)break;
			if (problemSolve[j] == 0)
				userCnt[i]--, problemSolve[j]++;
		}
	}
	for (int i = 1; i <= m; i++)
		if (problemSolve[i] == 0) jd = false;
	if (!jd) {
		printf("NO\n"); return 0;
	}
	else {
		printf("YES\n");
	}
	return 0;
}