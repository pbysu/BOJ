#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;
vector<pair<int, int>> v;
int n, len, dist = INF;
int calculate(pair<int, int> p, pair<int, int> q) {
	return (p.first - q.first)*(p.first - q.first) + (q.second - p.second)*(q.second - p.second);
}
int main() {
	scanf("%d", &n);
	v.resize(n);
	for (int x, y, i = 0; i < n; i++) 
		scanf("%d %d", &v[i].first, &v[i].second);
	sort(v.begin(), v.end(), [](pair<int, int> p, pair<int, int> q) {
		if (p.first != q.first)
			return p.first < q.first;
		else
			return p.second < q.second;});
	int temp;
	int ret = INF;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n && v[j].first - v[i].first < dist; j++) {
			temp = abs(v[i].second - v[j].second);
			if (temp > dist) continue;
			temp += v[j].first - v[i].first;
			temp *= sqrt(2);
			if (temp <= dist) dist = temp, ret = min(ret, calculate(v[i], v[j]));
		}
	}
	printf("%d", ret);
	return 0;
}