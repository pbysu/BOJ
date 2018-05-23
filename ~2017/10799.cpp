#include<iostream>

using namespace std;

int main() {

	char pos;
	int ans,ex, temp;
	ans = 0;
	temp = 0;
	while (scanf("%c", &pos) != EOF) {
	
		if (pos == '(')
			temp++;

		else if (pos == ')') {
			temp--;
			if (ex == '(') {
				ans += temp;
			}
			else ans++;
		}
		ex = pos;
	}
	printf("%d", ans);
	return 0;
}