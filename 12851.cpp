#include<cstdio>
#include<queue>
using namespace std;
int n, k;
bool visited[100001];
int func(int pos) {
	queue<int> q;
	q.push(pos);
	int cnt = 0;
	int tc = 0;
	bool flag = false;
	while (!q.empty()&&!flag) {
		cnt++;
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int t = q.front();
			visited[t] = true;
			if (t == k) flag = true, tc++;
			q.pop();
			if (t + 1 <= 100000 && visited[t+1]==false) q.push(t + 1);
			if (t - 1 >= 0 && visited[t-1]==false) q.push(t - 1);
			if (t*2<=100000 && visited[t*2]==false) q.push(t * 2);
		}
	}
	printf("%d\n%d\n",cnt-1,tc);
	return 0;
}
int main() {
	scanf("%d %d", &n, &k);
	func(n);
	return 0;
}