#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll num[3];
int main() {
	while (true) {
		scanf("%lld %lld %lld", &num[0], &num[1], &num[2]);
		if (num[0] == 0 && num[1] == 0 && num[2] == 0)
			break;
		sort(num, num + 3);

		if (num[0] * num[0] + num[1] * num[1] == num[2] * num[2])
			printf("right\n");
		else
			printf("wrong\n");
	}


	return 0;
}