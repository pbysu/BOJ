#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

struct asd {
	int a;
	int b;
};
queue <asd> st;

asd arr[110];

int main() {
	int tc;
	int ans;
	int x;
	int n, m;
	int check;
	priority_queue <int> p;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		while (!st.empty()) {
			st.pop();
		}
		while (!p.empty())
			p.pop();

		check = 0;
		x = 0;
		ans = 0;

		scanf("%d %d", &n, &m);

		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[j].a);
			arr[j].b = j;
			st.push(arr[j]);
			p.push(arr[j].a);
		}

		while (1) {
			if (st.front().a == p.top()) {
				if (st.front().b != m) {
					ans++;
					st.push(st.front());
					st.pop();
					p.pop();
				}
				else {
					ans++;
					break;
				}
			}
			else {
				st.push(st.front());
				st.pop();
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}