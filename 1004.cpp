#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
#include<math.h>

using namespace std;


struct pot {
	int x;
	int y;
	int r;
};
pot p1[1000];
pot p2[1000];
pot p3[51];

int main()
{
	int ans;
	int tc;
	int tc1;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		ans = 0;
		scanf("%d %d %d %d", &p1[i].x, &p1[i].y,
			&p2[i].x, &p2[i].y);
		scanf("%d", &tc1);
		for (int j = 0; j < tc1; j++) {
			scanf("%d %d %d", &p3[j].x, &p3[j].y, &p3[j].r);

			if ((pow((p2[i].x - p3[j].x), 2) + pow((p2[i].y - p3[j].y), 2) - pow(p3[j].r, 2) 
				< 0) && (pow((p1[i].x - p3[j].x), 2) + pow((p1[i].y - p3[j].y), 2) - pow(p3[j].r, 2) < 0))
			{
	
			}
			else if (pow((p1[i].x - p3[j].x), 2) + pow((p1[i].y - p3[j].y), 2) - pow(p3[j].r, 2) < 0) {
				ans++;
			}
			else if (pow((p2[i].x - p3[j].x), 2) + pow((p2[i].y - p3[j].y), 2) - pow(p3[j].r, 2) < 0) {
				ans++;
			}

		}
		printf("%d\n", ans);
	}
}