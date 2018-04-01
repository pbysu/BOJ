#include<cstdio>
#include<algorithm>


using namespace std;

int n, m;
int input[300000];
int Max = -1;

int func(int lo, int hi) {


	int k = 0;
	int mid = (lo + hi) >> 1;

	if (lo == hi) {

		for (int i = 0; i < m; i++) {
			k += (input[i] / mid);
			if (input[i] % mid) k++;
			if (k > n)
				return mid + 1;
		}

		return mid;


	}



	for (int i = 0; i < m; i++) {
		k += (input[i] / mid);
		if (input[i] % mid) k++;
		if (k > n)return func(mid + 1, hi);
	}

	return func(lo, mid);

}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &input[i]);
		Max = max(Max, input[i]);
	}

	printf("%d", func(1, Max));


	return 0;

}