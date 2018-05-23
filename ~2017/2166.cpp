#include<iostream>
#include<cmath>
using namespace std;
long double sum = 0;
pair<int, int> pos[10002];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &pos[i].first, &pos[i].second);

	pos[n] = pos[0];
	for (int i = 0; i < n; i++)
		sum += (long double)pos[i].first*pos[i + 1].second/2 - (long double)pos[i].second*pos[i + 1].first/2;
	printf("%.1Lf", fabs((long double)sum));
	return 0;
}