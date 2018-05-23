#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	string a;
	queue<int> q;
	int tp;
	for (int i = 0; i < tc; i++) {
		cin >> a;
		if (a == "push") {
			scanf("%d",&tp);
			q.push(tp);
			
		}
		else if (a == "front") {
			if (q.empty()) {
				cout << -1;
			}
			else
				cout << q.front();

			cout << endl;
		}
		else if (a == "back") {
			if (q.empty()) {
				cout << -1;
			}
			else
				cout << q.back();

			cout << endl;
		}
		else if (a == "empty") {
			if (q.empty()) {
				cout << 1;
			}
			else
				cout << 0;

			cout << endl;
		}
		else if (a == "pop") {
			if (q.empty()) {
				cout << -1;
			}
			else{
				cout << q.front();
				q.pop();
			}
			cout << endl;
		}
		else if (a == "size") {
			cout << q.size();
			cout << endl;
		}

	}
	return 0;
}