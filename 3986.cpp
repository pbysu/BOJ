#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int n, ans;
char str[100010];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &str);
		stack<char> st;
		int k = strlen(str);
		for (int j = 0; j < k; j++) {
			if (!st.empty()) {
				if (st.top() == str[j]) {
					st.pop();
				}
				else {
					st.push(str[j]);
				}
			}
			else {
				st.push(str[j]);
			}
		}
		if (st.empty()) ans++;
	}
	printf("%d\n", ans);
	return 0;
}