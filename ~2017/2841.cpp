#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
stack<int> s[7];
int n, m;
int main() {
	for (int i = 1; i < 7; i++) {
		s[i].push(-1);
	}
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (int f,b, i = 0; i < n; i++){
		scanf("%d%d", &f, &b);
		while (s[f].top() > b) {
			ans++;
			s[f].pop();
		}
		if (s[f].top() != b)
			s[f].push(b), ans++;
	}

	printf("%d", ans);
	return 0;
}