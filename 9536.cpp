#include<stdio.h>	
#include<string.h>
#include<iostream>
#include<string>
#include<set>
using namespace std;
int n;
int tc;
char allStr[10001];
char ani[100][101];
string who, goes, that;
char* fox;
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		getchar();
		cin.getline(allStr, 10001);
		int idx = 0;
		while (1) {
			cin >> who >> goes;
			if (goes == "goes") {
				scanf("%s",&ani[idx++]);
			}
			else {
				char trash[10];
				for (int i = 0; i < 3; i++) {
					scanf("%s", trash);
				}
				break;
			}
		}
		fox = strtok(allStr, " ");
		while (fox != NULL) {
			bool jd = 1;
			for (int k = 0; k < idx; k++) {
				if (!strcmp(fox, ani[k])) {
					jd = 0;
					break;
				}
			}
			if (jd)
				printf("%s ", fox);
			fox = strtok(NULL, " ");
		}
		printf("\n");
	}
	return 0;
}