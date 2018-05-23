#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
using namespace std;
int main() {
	int tc, s, n, q, p;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int cost = 0;
		scanf("%d", &s);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &q, &p);
			cost += q*p;
		}
		cout << cost+s<<endl;
	
	}
}