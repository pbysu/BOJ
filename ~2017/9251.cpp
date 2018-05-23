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
	table.resize(as, (vector<int>(bs)));
	for (int i = 0; i < as; i++) {
		for (int j = 0; j < bs; j++) {
			if (a[i] == b[j]) {
				if (i*j == 0)table[i][j] = 1;
				else
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else {
				table[i][j] = max(j!=0?table[i][j - 1]:0,i!=0? table[i - 1][j]:0);
			}
		}
	}
	r = as-1;
	c = bs-1;
	printf("%d\n", table[r][c]);
	return 0;
}