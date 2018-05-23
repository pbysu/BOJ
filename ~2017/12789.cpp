#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
queue<int> q;
stack<int>s;
int main() {
	int n, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		q.push(tmp);
	}
	int pos = 1;

	while (!q.empty()) {


		if (q.front() == pos) {
			q.pop();
			pos++;
			continue;
		}
		if (q.front() != pos) {

			if (!s.empty()) {
				if (s.top() == pos) {
					s.pop();
					pos++;
					continue;
				}
				else if (s.top() < q.front()) {
					return printf("Sad");
				}
				else  if (q.front() < s.top()) {
					s.push(q.front());
					q.pop();
					continue;
				}
			}
			else {
				s.push(q.front());
				q.pop();
				continue;
			}
		}
	}

	printf("Nice");

	return 0;
}