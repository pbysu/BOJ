#include<iostream>
#include<algorithm>
#include <string>
using namespace std;

string a;
string b;
char map[1000][1000];

int main() {
	cin >> a >> b;


	int x = a.length();
	int y = b.length();
	int i, j;
	int col, row;
	bool jd = false;
	for ( i= 0; i < x; i++) {
		for ( j= 0; j < y; j++) {
			if (a[i] == b[j]) {
				col = i;
				row = j;
				jd = true;
				break;
			}
		}
		if (jd == true) break;
	}


	for (int k = 0; k < x; k++) {
		map[j][k] = a[k];
	}
	for (int k = 0; k < y; k++) {
		map[k][i] = b[k];
	}

	for (i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (map[i][j] == NULL)
				printf(".");
			else
			printf("%c", map[i][j]);
			
		}
		printf("\n");
	}

	return 0;
}