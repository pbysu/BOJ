#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, L;
int pos[111];
int dist[111];

int check(int mid) {
	int ret = 0;
	for (int i = 0; i < N + 1; i++) {
		ret += (dist[i]) / mid;
	}
	return ret;
}

int main() {
	cin >> N >> M >> L;
	for (int i = 0; i < N; i++) {
		cin >> pos[i];
	}
	sort(pos, pos + N);
	int left = L / (N + M);
	int right = 0;
	dist[0] = pos[0] - 1;
	for (int i = 1; i < N; i++) {
		dist[i] = pos[i] - pos[i - 1] - 1;
	}
	dist[N] = L - pos[N - 1] - 1;
	for (int i = 0; i < N + 1; i++) {
		right = max(right, dist[i]);
	}

	left = 0;
	while (left <= right) {

		int mid = (left + right) / 2;

		if (check(mid) <= M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << left << "\n";
	return 0;
}