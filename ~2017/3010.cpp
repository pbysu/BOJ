#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int dr[] = { 1, -1,0,0 };
int dc[] = { 0,0,1,-1 };
stack<pair<int, int>> s;
char arr[20][20];
char tmp;
int col = 0;
int ans = 0;
int main() {
	for (int i = 0; i < 7;) {
		i++;
		col = 2;
		while (1) {
			col++;
			scanf("%c", &tmp);
			if (tmp == '\n')
				break;
			if (tmp == '.') s.push({ i + 3,col });
			arr[i + 3][col] = tmp;
		}
	}

	int ssize = s.size();

	for (int i = 0; i < ssize; i++) {
		int r = s.top().first;
		int c = s.top().second;
		s.pop();

		for (int j = 0; j < 4; j++) {
			int tr = r + dr[j];
			int tc = c + dc[j];
			int ttr = tr + dr[j];
			int ttc = tc + dc[j];

			if (arr[tr][tc] == 'o' && arr[ttr][ttc] == 'o') {
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}