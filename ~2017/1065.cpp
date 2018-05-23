#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;


int main() {
	int num, temp, pos,ex, d;

	scanf("%d", &num);

	int ans = 0;
	for (int i = 1; i <= num; i++) {

		temp = i;
		int cnt = 1;
		bool jd = true;
		while (temp) {

			pos = temp % 10;
			temp /= 10;
			if (cnt == 2) d = pos - ex;
			else if (cnt > 2 && pos - ex != d) {
				jd = false;
				break;
			}
			ex = pos;
			cnt++;
		}
		if (jd) ans++;


	}

	printf("%d", ans);
	return 0;
}