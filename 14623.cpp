#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
stack<bool> s;
queue<bool> q;
typedef long long ll;
ll A, B;
char tmp;
int main() {
	while (scanf("%c", &tmp)) {
		if (tmp == '\n') break;
		q.push(tmp-'0');
	}
	while (!q.empty()) {
		A <<= 1;
		A +=q.front();
		q.pop();
	}
	
	while (scanf("%c", &tmp)) {
		if (tmp == '\n') break;
		q.push(tmp - '0');
	}
	while (!q.empty()) {
		B <<= 1;
		B += q.front();
		q.pop();
	}
	
	A = A*B;
	while (A != 0) {
		s.push(A % 2);
		A >>= 1;
	}

	while (s.size()) {
		printf("%d", s.top());
		s.pop();
	}
	return 0;
}