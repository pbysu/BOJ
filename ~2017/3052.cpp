#include<iostream>

bool arr[1001];
int main() {
	int tmp;
	int idx;
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &tmp);
		idx = tmp % 42;

		if (arr[idx] == false) {
			arr[idx] = true;
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}