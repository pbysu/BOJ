#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define INF 987654321
using namespace std;
int cnt;
int open[2];
vector<int> order;
map<pair<int, int>, int> m;
int bit;

int findEmpty(int pos, int wall, int jd) {
	if (jd == 0) {
		for (int i = wall - 1; i >= 0; i--) {
			if (!((pos >> i) & 1)) {
				return i;
			}

		}
	}
	else {
		for (int i = wall; i < cnt; i++) {
			if (!((pos >> i) & 1))
				return i;
		}
	}
	return -1;
}
int func(int pos, int idx) {
	if (idx == order.size()) return 0;
	int wall = order[idx];

	if (m.find({ pos,idx }) == m.end()) {
		int ret = INF;
		int right = findEmpty(pos, wall, 0);
		int left = findEmpty(pos, wall, 1);


		if (right != -1) {
			int rightPos = pos - pow(2, wall) + pow(2, right);
			ret = min(func(rightPos, idx + 1) + wall - right, ret);
		}

		if (left != -1) {
			int leftPos = pos - pow(2, wall) + pow(2, left);
			ret = min(func(leftPos, idx + 1) + left - wall, ret);
		}

		if(ret!=INF)
			return m[{ pos, idx }] = ret;
		else return INF;
	}
	else
		return m[{pos, idx}];
}


int main() {
	int tmp, tc;
	scanf("%d", &cnt);
	bit = pow(2, cnt) - 1;
	scanf("%d %d", &open[0], &open[1]);
	bit =bit- (pow(2, cnt - open[0]) + pow(2, cnt - open[1]));
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		scanf("%d", &tmp);
		order.push_back(cnt - tmp);
	}

	int ans = func(bit, 0);
	printf("%d", ans);
	return 0;
}