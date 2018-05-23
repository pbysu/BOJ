#include<string>
#include<iostream>
#include<stack>

using namespace std;


int main() {
	int tc;
	scanf("%d", &tc); 
	string ord;
	int tp;
	stack <int>s;


	for (int i = 0; i < tc; i++) {
		cin >> ord;
		if (ord == "push") {
			scanf("%d", &tp);
			s.push(tp);
		}
		else if (ord == "top") {
			if (!s.empty())
				printf("%d\n", s.top());
			else
				printf("-1\n");
		}
		else if (ord == "size") {
			printf("%d\n",s.size());
		}
		else if (ord == "pop") {
			if (!s.empty()) {
				printf("%d\n", s.top());
				s.pop();
			}

			else
				printf("-1\n");
			
		}
		else if (ord == "empty") {
			if (s.empty())
				printf("1\n");
			else
				printf("0\n");
		}
	}

	return 0;
}