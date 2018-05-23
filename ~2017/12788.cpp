#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;
int arr[1100];
int ans[1100];
int main() {
	int tc;
	int n, m;
	scanf("%d\n%d %d", &tc, &n, &m);
	int need = n*m;
	for (int i = 0; i < tc; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + tc);
	reverse(arr, arr + tc);
	ans[0] = arr[0];
	for (int i = 1; i < tc; i++) {
		ans[i] = ans[i - 1] + arr[i];
	}
	int jd = 0;
	for (int i = 0; i < tc; i++) {
		if (ans[i] >= need) {
			jd = 1;
			printf("%d", i + 1);
			break;
		}
	}
	if(jd==0)printf("STRESS");
}