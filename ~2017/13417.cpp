#include<iostream>
#include<algorithm>
#include<list>
#include<queue>
#define INF 987654321;
using namespace std;
list<char> lis;
queue<char>q;
int main() {
	int tc;
	int n;
	char minChar;
	char temp;
		int qsize;
	scanf("%d", &tc);
	while (tc--) {
		minChar = 'Z';
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			getchar();
			scanf("%c", &temp);
			q.push(temp);
		}

		qsize = q.size();

		while (qsize--) {
			if (q.front() > minChar)
				lis.push_back(q.front());
			else {
				lis.push_front(q.front());
				minChar = min(minChar, lis.front());
			}
			q.pop();
		}

		qsize = lis.size();

		while (qsize--) {
			printf("%c", lis.front());
			lis.pop_front();
		}
		printf("\n");
	}

}