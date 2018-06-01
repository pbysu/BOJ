#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, u, v;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &u, &v);
		printf("%d\n", u + v);
	}

	return 0;
}