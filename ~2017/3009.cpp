#include<cstdio>
#include<map>	
#include<algorithm>
using namespace std;
map<int, int> mx;
map<int, int> my;
int i, tmp;
int main() {
	for (i = 0; i < 3; i++) {
		scanf("%d", &tmp);
		mx[tmp]++;
		scanf("%d", &tmp);
		my[tmp]++;
	}
	int x, y;
	for (auto it = mx.begin(); it != mx.end(); it++) {
		if (it->second == 1) {
			x = it->first;
		}
	}
	for (auto it = my.begin(); it != my.end(); it++) {
		if (it->second == 1) {
			y = it->first;
		}
	}

	printf("%d %d", x, y);
	return 0;
}