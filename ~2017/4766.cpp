#include<cstdio>
using namespace std;
float pos, ex;
int main() {
	scanf("%f", &ex);
	while (1) {
		scanf("%f", &pos);
		if (pos == 999) {
			break;
		}
		printf("%.2f\n", pos - ex);
		ex = pos;
	}
	return 0;
}