#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int grade[100001][2];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &grade[i][0], &grade[i][1]);
	}
	int Max = -1, tmp, tc;
	for (int i = 1; i <= 5; i++) {
		tmp = 0;
		for (int j = 0; j < n; j++) {
			if (grade[j][0] == i || grade[j][1]==i) {
				tmp++;
				if (tmp > Max) {
					Max = tmp;
					tc = i;
				}
			}
			else {
				tmp = 0;
			}
		}
	}
	printf("%d %d\n", Max, tc);
	return 0;
}