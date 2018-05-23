#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue <int> pq;
int n;
int main() {
	scanf("%d", &n);
	for (int tmp, i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &tmp);
			pq.push(-tmp);
			if (pq.size() > n)
				pq.pop();
		}
	int t = n-1;
	printf("%d", -pq.top());
	return 0;
}