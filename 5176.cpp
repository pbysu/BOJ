#include<cstdio>
#include<set>
using namespace std;
//float pos, ex;
//int main() {
//	scanf("%f", &ex);
//	while (1) {
//		scanf("%f", &pos);
//		if (pos == 999) {
//			break;
//		}
//		printf("%.2f\n", pos - ex);
//		ex = pos;
//	}
//	return 0;
//}

set<int> s;
int t, p, m;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &p, &m);
		set<int>s;
		for (int temp, i = 0; i < p; i++) {
			scanf("%d", &temp);
			s.insert(temp);
		}

		printf("%d\n", p - s.size());
	}
	return 0;
}