#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;
int n;
int main() {
	scanf("%d", &n);
	int ans = 0;
	int i;
	int ret = 0;
	for (i = 2; i*i <=n; i++) {
		if (n%i == 0) {
			ret = n / i; break;
		}
	}
	if (ret == 0) ret = 1;
	printf("%d",n-ret );
	return 0;
}