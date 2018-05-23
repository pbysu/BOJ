#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char str[201];
int arr[5] = { 0,1,0,0,2 };
int main()	{
	scanf("%s", &str);
	int sz = strlen(str);
	for (int i = 0; i < sz; i++) {
		if (str[i] == 'A') {
			swap(arr[1], arr[2]);
		}
		else if (str[i] == 'B') {
			swap(arr[1], arr[3]);
		}
		else if (str[i] == 'C') {
			swap(arr[1], arr[4]);
		}
		else if (str[i] == 'D') {
			swap(arr[2], arr[3]);
		}
		else if (str[i] == 'E') {
			swap(arr[2], arr[4]);

		}
		else if (str[i] == 'F') {
			swap(arr[3], arr[4]);
		}
	}
	pair<int, int> ans;
	for (int i = 1; i < 5; i++) {
		if (arr[i] == 1)
			ans.first = i;
		else if (arr[i] == 2)
			ans.second = i;
	}

	printf("%d\n%d\n", ans.first, ans.second);
}