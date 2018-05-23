#include<iostream>
using namespace std;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp < m) printf("%d ", tmp);
	}
	return 0;
}