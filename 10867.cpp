#include <iostream>
#include <set>

using namespace std;
set<int> myset;
int main() {

	int tc;
	int temp;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		scanf("%d", &temp);
		myset.insert(temp);
	}
	for (set<int>::iterator it = myset.begin(); it != myset.end(); it++) {
		printf("%d ", *it);
	}
	return 0;
}