#include<iostream>
#include<algorithm>

using namespace std;

char alpa[520];
int number[520];
int main() {
	int tc;
	int num;
	char jud;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		scanf("%d %c", &num, &jud);
		if (jud == 'C') {
			for (int j = 0; j < num; j++) cin >> alpa[j];
			for (int k = 0; k < num; k++) {
				printf("%d ", alpa[k] - 'A'+1);
			}
		}
		else {
			for (int j = 0; j < num; j++) cin >> number[j];
			for (int k = 0; k < num; k++)
				printf("%c ", number[k] + 'A'-1);
		}
		
		printf("\n");
	}
}