#include<iostream>
#include<algorithm>
using namespace std;
int psum[1 << 10 + 1][1 << 10 + 1], n, m;	
int main() {
	scanf("%d %d", &n,&m);
	for(int i =1; i<= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &psum[i][j]);
			psum[i][j] += psum[i - 1][j] + psum[i][j - 1]-psum[i-1][j-1];
		}

	for (int x,y,p,q, i = 0; i < m; i++) {
		scanf("%d %d %d %d", &x, &y, &p, &q);
		printf("%d\n", psum[p][q] - psum[p][y - 1] - psum[x - 1][q] + psum[x - 1][y - 1]);
	}
	return 0;
}