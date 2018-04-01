#include<cstdio>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int k = 0;
	while (1 +k*(6+ 6 * k)/2 <n)
		k++;
	printf("%d", k+1);
	return 0;
}