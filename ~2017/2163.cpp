#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	int low;
	int hig;
	hig = max(n1, n2);
	low = min(n1, n2);

	printf("%d", (hig-1)+(hig)*(low - 1));
}