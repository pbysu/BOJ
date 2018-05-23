#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<float> input;
int u;
float s;
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	input.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d %f", &u, &s);
			if (input[u - 1] < s) {
				input[u - 1] = s;
			}
		}
	}
	double sum = 0;
	sort(input.begin(), input.end());
	for (int i = n-1; i>n-1-k; i--) {
		sum += (double)input[i];
	}
	printf("%.1lf\n", sum);
	return 0;
}