#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct id {
	int num;
	int idx;
};
vector<id> findInput;

bool func(id p, id q) {
	if (p.num != q.num) {
		return p.num < q.num;
	}
	else {
		return
			p.idx > q.idx;
	}
}
bool idxfunc(id p, id q) {
	if (p.idx != q.idx)
		return p.idx < q.idx;
}
bool uni(id p, id q) {
	if (p.num == q.num) {
		return true;
	}
	else
		return false;
}
int main() {
	int k, l;
	scanf("%d %d", &k, &l);
	int num;

	for (int i = 0; i < l; i++) {
		id temp;
		scanf("%d", &num);
		temp.num = num;
		temp.idx = i;
		findInput.push_back(temp);
	}

	sort(findInput.begin(), findInput.end(), func);
	vector<id>::iterator it = unique(findInput.begin(), findInput.end(), uni);
	findInput.resize(distance(findInput.begin(), it));
	sort(findInput.begin(), findInput.end(), idxfunc);
	int ten;

	if (k > findInput.size()) {
		k = findInput.size();
	}

	for (int i = 0; i < k; i++) {
		ten = pow(10, 7);

		while (findInput[i].num / ten == 0) {
			printf("0");
			ten = ten / 10;
			if (ten == 1) {
				break;
			}
		}
		printf("%d\n", findInput[i].num);
	}

	return 0;
}