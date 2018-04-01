#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int i = 0;
int temp;
int idx;
vector<int> preorder;
vector<int> inorder;

void traversal(int start, int finial) {
	if (start == finial)return;
	for (int i = start; i < finial; i++) {
		if (preorder[idx] == inorder[i]) {
			idx++;
			if (start != i)
				traversal(start, i);
			if (i + 1 != finial) traversal(i + 1, finial);
			printf("%d\n", inorder[i]);
			return;
		}
	}
}

int main() {
	while (scanf("%d", &temp)!=EOF) {
		preorder.push_back(temp);
		i++;
	}

	inorder = preorder;

	sort(inorder.begin(), inorder.end());
	idx = 0;
	traversal(0, i);
	return 0;
}