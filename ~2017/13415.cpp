#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;
stack<pair<int, char>> s;
stack<pair<int, char>> sAfter;
int input[100001];

int main() {
	int sizet;
	scanf("%d", &sizet);

	for (int i = 1; i <= sizet; i++) {
		scanf("%d", &input[i]);
	}
	int k;
	scanf("%d", &k);
	int a, b;
	int t = 1;
	int maxAB = 0;

	for (int i = 1; i <= k; i++) {
		scanf("%d %d", &a, &b);
		s.push({ a,'a' });
		s.push({ b,'b' });
	}
	int tempSize = s.size();

	for (int i = 0; i < tempSize; i++) {
		if (maxAB < s.top().first) {
			sAfter.push(s.top());
			maxAB = s.top().first;
		}
		s.pop();
	}

	tempSize = sAfter.size();

	for (int i = 0; i < tempSize; i++) {
		if (sAfter.top().second == 'a') {
			sort(&input[1], &input[1] + sAfter.top().first);
		}
		else {
			sort(&input[1], &input[1] + sAfter.top().first);
			reverse(&input[1], &input[1] + sAfter.top().first);
		}
		sAfter.pop();
	}

	for (int i = 1; i <= sizet; i++) {
		printf("%d ", input[i]);
	}
	return 0;
}