#include<vector>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

vector<vector<string>> v;
char str[100];
char tmp;
int main() {
	int n;
	cin >> n;
	v.resize(n);
	getchar();
	for (int i = 0; i < n; i++) {
		int idx = 0;
		while (1) {
			scanf("%c", &str[idx]);
			if (str[idx] == '\n') {
				str[idx] = '\0';
				v[i].push_back(str);	
				memset(str, 0, sizeof(str));
				break;
			}
			else if (str[idx] == ' ') {
				str[idx] = '\0';
				v[i].push_back(str);
				memset(str, 0, sizeof(str));
				idx = 0;
			}
			else
			idx++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0)cout << "god";
			else
			cout << v[i][j];
		}
		printf("\n");
	}

	return 0;
}