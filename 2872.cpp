#include<cstdio>
int n, arr[300010], val;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);
	val = n;
	for (int i = n - 1; i >= 0; i--) 
		if (arr[i] == val) val--;
	printf("%d", val);
	return 0;
}