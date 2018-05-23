#include<cstdio>
#include<vector>
using namespace std;
int r, c;
char table[55][55];
vector<pair<int,int>> v;
int main() {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		getchar();
		for (int j = 1; j <= c; j++) {
			scanf("%c", &table[i][j]);
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (table[i][j] == '#') continue;
			if ((i - 1 == 0 || table[i - 1][j] == '#') && i + 2 <= r && table[i + 1][j] == '.' && table[i + 2][j] == '.') {
				v.push_back({ i,j });
			}
			else if ((j - 1 == 0 || table[i][j - 1] == '#') && j+2<=c&& table[i][j + 1] == '.'&&table[i][j + 2] == '.') {
				v.push_back({ i,j });
			}
		}
	}
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}