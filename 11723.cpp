#include<set>
#include<iostream>
#include<string>
#include<cstring>


using namespace std;

set<int> s;
char arr[10];
int main() {
	int tc;
	string a;
	int temp;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		
		scanf("%s", arr);
		scanf("%d", &temp);
		if (strcmp(arr,"add")==0) {
			s.insert(temp);
		}
		else if (strcmp(arr,"remove") == 0){
			s.erase(temp);
		}
		else if (strcmp(arr,"toggle") == 0) {
			if (s.count(temp)) {
				s.erase(temp);
			}
			else {
				s.insert(temp);
			}
		}
		else if (strcmp(arr,"check") == 0) {
			if (s.count(temp)) {
				printf("%d\n", 1);
			}
			else
				printf("0\n");
		}
		else if (strcmp(arr,"all") == 0) {
			for (int j = 1; j <= 20; j++) {
				s.insert(j);
			}
		}
		else {
			s.clear();
		}
	}

	return 0;
}