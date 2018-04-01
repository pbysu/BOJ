#include<algorithm>
#include<iostream>
using namespace std;
pair<int, int> tmp;
int main() {
	tmp.first = 0;
	int temp;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &temp);
		if (tmp.first < temp) {
			tmp.first = temp;
			tmp.second = i + 1;
		}
	}
	printf("%d\n%d", tmp.first, tmp.second);

}