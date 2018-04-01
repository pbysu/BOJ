#include<cstdio>
#include<cstring>
int n, k;
int arr[100001];
int tmp[100001];
int ans = 0, ret = 0;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		ans += tmp[i];
		if (arr[i] ^ (ans & 1)) {
			if (i + k > n) {
				printf("Insomnia");
				return 0;
			}
			++ans;
			++ret;
			tmp[i + k] = -1;
		}
	}
	printf("%d", ret);
	return 0;
}