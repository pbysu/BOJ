#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node{
	int prv;
	vector<int> next;
};
vector<node> edge;
int root;
int func(int pos, int& remove) {
	if (pos == remove) {
		if (edge[pos].prv ==pos || edge[edge[pos].prv].next.size()>1)
			return 0;
		else
			return 1;
	}
		
	if (edge[pos].next.size() == 0)
		return 1;
	int ret = 0;
	for (int i = 0; i < edge[pos].next.size(); i++) {
		ret += func(edge[pos].next[i],remove);
	}
	return ret;
}

int main() {
	int n, remov;

	scanf("%d", &n);
	edge.resize(n);
	for (int tmp, i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp == -1)
			edge[i].prv = i;
		else
			edge[i].prv = tmp;
		if (tmp != -1)
			edge[tmp].next.push_back(i);
		else
			root = i;
	}
	scanf("%d", &remov);
	printf("%d", func(root, remov));
	return 0;
}