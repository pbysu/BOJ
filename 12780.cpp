#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;
char n[100010];
char m[12];
int main() {
	scanf("%s", n);
	scanf("%s", m);
	int nSize = strlen(n);
	int msize = strlen(m);
	int ans = 0;
	bool jd = false;

	for (int i = 0; i < nSize; i++) {
		

		if (n[i] == m[0]) {
			jd = true;
			for (int j = 0; j < msize; j++) {
				if (m[j] != n[i + j]) {
					jd = false;
					break;
				}
			}
			if (jd == true) ans++;
		}
	}

	printf("%d", ans);
}