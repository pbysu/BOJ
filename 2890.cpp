#include<cstdio>	
#include<cstring>
#include<vector>	
#include<algorithm>
using namespace std;
int r, c;
char tmp;
pair<int, int> arr[9];
int ans[9];
int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%c", &tmp);
			if (tmp > '0' && tmp <= '9' && arr[tmp-'0'-1].first < j) {
				arr[tmp - '0'-1].first = j;
				arr[tmp - '0'-1].second = tmp - '0'-1;
			}
		}
		getchar();
	}
	int rank = 0;
	int ex = -1;
	sort(arr, arr + 9, [](pair<int, int> p, pair<int, int> q) {
		if (p.first != q.first)
			return p.first > q.first;
		else
			return p.second < q.second;
	});
	for (int i = 0; i < 9; i++) {
		if (arr[i].first != ex) {
			rank++;
			ex = arr[i].first;
		}
		ans[arr[i].second] = rank;
	}
	for (int i = 0; i < 9; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}