#include<iostream>
#include<algorithm>

using namespace std;

char input[100001];
char result[100001];
int main() {
	int t;
	int n, countB, countA;
	char temp;
	scanf("%d", &t);
	getchar();
	while (t--) {
		countB = 0;
		countA = 0;
		scanf("%d", &n);
		getchar();
		for (int i = 1; i <= n; i++) {
			scanf("%c", &input[i]);
		}
		getchar();
		for (int i = 1; i <= n; i++) {
			scanf("%c", &temp);
			if (input[i] != temp) {
				if (input[i] == 'B')
					countB++;
				else
					countA++;
			}
		}
		if (countA < countB) swap(countA, countB);

		int ans = countA;
		printf("%d\n", ans);

	}
	return 0;
}