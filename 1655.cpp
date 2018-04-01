#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
int n, tmp;
priority_queue<int> le;
priority_queue<int, vector<int>, std::greater<int>> ri;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (le.size() > ri.size()) {
			ri.push(tmp);

		}
		else {
			le.push(tmp);
		}
		if (!le.empty()&&!ri.empty()&&le.top() > ri.top()) {
			tmp = le.top();
			le.pop();
			le.push(ri.top());
			ri.pop();
			ri.push(tmp);
		}
		printf("%d\n", le.top());
	}
	return 0;
}