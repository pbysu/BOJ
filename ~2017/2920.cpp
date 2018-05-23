#include<iostream>
using namespace std;
int table[8];
bool ic;
bool de;
bool mix;
int main() {
	int pos, ex;
	scanf("%d", &ex);

	for (int i = 1; i < 8; i++) {
		scanf("%d", &pos);
		if (pos > ex) {
			ic = true;
		}
		else if (pos < ex)
			de = true;
		else
			mix = true;
		
		ex = pos;
	}

	if (ic&&de || mix) printf("mixed");
	else if (ic)printf("ascending");
	else printf("descending");
	return 0;
}