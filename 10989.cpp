#include<cstdio>
int n, arr[10010];
int main() {
	scanf("%d", &n);
	for (int idx, i = 0; i < n; i++) scanf("%d", &idx), arr[idx]++;
	for (int i = 0; i < 10010; i++) for (int j = 0; j < arr[i]; j++)printf("%d\n", i);
}