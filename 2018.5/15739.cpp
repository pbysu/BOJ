#include<cstdio>
using namespace std;
int n;
typedef long long ll;
bool visited[500050];
ll arr[101][101];

int main() {
	scanf("%d", &n);
	int lim = n*(n*n + 1) / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lld", &arr[i][j]);
		}
	}
	ll ex = 0;
	ll pos = 0;

	for (int j = 0; j < n; j++)
		ex += arr[0][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pos += arr[i][j];
			if (visited[arr[i][j]] || lim<arr[i][j]) {

				printf("FALSE\n");
				return 0;
			}
			visited[arr[i][j]] = true;
		}

		if (ex != pos) {
			printf("FALSE\n");
			return 0;
		}
		pos = 0;

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pos += arr[j][i];
		}
		if (ex != pos) {
			printf("FALSE\n");
			return 0;
		}
		pos = 0;
	}

	for (int i = 0; i < n; i++) {
		pos += arr[i][i];
	}
	if (ex != pos) {
		printf("FALSE\n");
		return 0;
	}

	pos = 0;
	for (int i = n - 1; i >= 0; i--) {
		pos += arr[i][i];
	}
	if (ex != pos) {
		printf("FALSE\n");
		return 0;
	}

	printf("TRUE\n");
	return 0;
}