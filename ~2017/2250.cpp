#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
queue<int> q;
int temp;
struct node {
	int prev;
	int left, right;
};
vector<node> v;
pair<int, int> memory[10010];
vector<bool>check;
int cnt = 1;
int height = 0;
vector<vector<int>> remeber;

void inOrderTraversal(node &pos, int h) {
	if (pos.left != -1) inOrderTraversal(v[pos.left], h+1);
	if (memory[h].first == 0) memory[h].first = cnt;
	memory[h].second = cnt++;
	if (pos.right != -1) inOrderTraversal(v[pos.right], h + 1);
}
int findNode(int pos) {
	if (v[pos].prev != 0)
		return findNode(v[pos].prev);
	return pos;
}
int main() {
	int n;
	scanf("%d", &n);
	v.resize(n+1);
	for (int a,b,c, i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].left = b;
		v[a].right = c;
		if(b!=-1) v[b].prev = a;
		if(c!=-1) v[c].prev = a;
	}
	remeber.resize(10010);
	
	int s = findNode(1);
	inOrderTraversal(v[s], 1);
	int k = 1;
	pair<int, int> ans = { 0,0 };
	int tmp;
	while (memory[k].first != 0) {
		tmp = memory[k].second - memory[k].first + 1;
		if (ans.first < tmp) ans.first = tmp, ans.second = k;
		k++;
	}
	printf("%d %d\n", ans.second,ans.first);
	return 0;
}