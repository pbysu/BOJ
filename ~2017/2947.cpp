#include<cstdio>
#include<algorithm>

using namespace std;
int arr[5];
bool check() {
	for (int i = 0; i < 4; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}
void print() {
	for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
	printf("\n");
}
int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}

	while (!check()) {
		for (int i = 0; i < 4; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				print();
			}
		}
	}
	return 0;
}