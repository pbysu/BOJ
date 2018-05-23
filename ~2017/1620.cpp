#include<iostream>
#include<stack>
#include<string>
#include<map>

using namespace std;
map<string, int> ma;
char name[100010][23];
char check[22];

int main() {
	
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", name[i]);
		ma[name[i]] = i +1;
	}
	while (m--) {
		scanf("%s", check);
		if (check[0] < 'A') {
			printf("%s\n", name[atoi(check)-1]);
		}
		else{
			printf("%d\n", ma[check]);
		}
	}
	return 0;
}