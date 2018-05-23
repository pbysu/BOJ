#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string a, b;
int as, bs, r, c;
vector<vector<int>> table;
vector<int>ans;

int main() {
	cin >> a >> b;
	as = a.size(); bs = b.size();
	table.resize(as+1, (vector<int>(bs+1)));

	for (int i = 1; i <= as; i++) {
		for (int j = 1; j <= bs; j++) {
			if (a[i-1] == b[j-1]) table[i][j] = table[i - 1][j - 1] + 1;
			else {
				table[i][j] = max(table[i][j - 1], table[i - 1][j]);
			}
		}
	}
	r = as;
	c = bs;
	printf("%d\n", table[r][c]);
	while (table[r][c] != 0) {
		if (table[r][c] == table[r][c - 1])
			c--;
		else if (table[r][c] == table[r - 1][c])
			r--;
		else if (table[r][c] - 1 == table[r - 1][c - 1])
			ans.push_back(r-1), r--, c--;
	}
	for (int i = ans.size()-1; i>=0; i--) {
		printf("%c", a[ans[i]]);
	}

	return 0;
}