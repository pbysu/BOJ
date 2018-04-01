#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

struct x {
	char s[60];
};

bool cmp(x p, x q) {
	if (strlen(p.s) != strlen(q.s)) {
		return strlen(p.s) < strlen(q.s);
	}
	else {
		int to1 = 0;
		int to2 = 0;
		
		for (int i = 0; i < strlen(p.s); i++) {
			if (p.s[i] <= '9') to1 += p.s[i] - '0';
		}
		for (int i = 0; i < strlen(q.s); i++) {
			if (q.s[i] <= '9') to2 += q.s[i] - '0';
		}
		int i = 0;
		if(to1!=to2) return to1 < to2;
		else {
			while (true) {
				if (p.s[i] != q.s[i]) { break;  }
				else i++;
			}
			return p.s[i] < q.s[i];
		}
	}
}



x arr[1010];

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%s", arr[i].s);
	}
	sort(arr, arr + tc, cmp);
	for (int i = 0; i < tc; i++) {
		printf("%s\n", arr[i].s);
	}
	return 0;
}