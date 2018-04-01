#include<iostream>
#include<queue>
#include <cstring>
using namespace  std;
queue<pair<char*,int>> q;
queue<char*> p;
vector<vector<char>>arr;
vector<vector<char>>arr1;
vector<vector<char>> ans;
int main() {
	int t, cnt;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &cnt);
		arr.resize(cnt);
		arr1.resize(cnt);
		ans.resize(cnt);
		for (int i = 0; i < cnt; i++) {
			arr1[i].resize(101);
			scanf("%s", &arr1[i][0]);
			p.push(&arr1[i][0]);
		}

		for (int i = 0; i < cnt; i++) {
			arr[i].resize(101);
			scanf("%s", &arr[i][0]);
			q.push({ &arr[i][0],i });
		}
		for (int i = 0; i < cnt; i++) {
			ans[i].resize(101);
			scanf("%s",& ans[i][0]);
		}
		while (!p.empty()) {
			if (!strcmp(q.front().first, p.front())) {
				printf("%s ", &ans[q.front().second][0]);
				q.pop();
				p.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}
}