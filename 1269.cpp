#include<iostream>
#include<set>
using namespace std;

set<int> s;

int main() {

	int n, m;
	int tmp, ans = 0;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		s.insert(tmp);
		ans++;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		if (s.find(tmp) == s.end()) {
			s.insert(tmp);
			ans++;
		}
		else ans--;
	}
	printf("%d", ans);



	return 0;
}