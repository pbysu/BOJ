#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t, n;
vector<int>v;
vector<int> q;
vector<int> save;
bool check[15510];

void func(int pos, const int &lim) {
	if (pos == t)
		return;
	int siz = save.size();
	for (int i = 0; i < siz; i++) {
		int right = abs(save[i] + v[pos]);
		int left = abs(save[i] - v[pos]);
		int noop = v[pos];

		if (right <= lim && !check[right]) {
			save.push_back(right);
			check[right] = true;
		}
		if (left <= lim && !check[left]) {
			save.push_back(left);
			check[left] = true;
		}
		if (noop<=lim &&!check[noop]) {
			save.push_back(noop);
			check[noop] = true;
		}
	}
	return func(pos+1, lim);
}

int main() {
	scanf("%d", &t);
	v.resize(t);
	for (int i = 0; i < t; i++)
		scanf("%d", &v[i]);

	scanf("%d", &n);
	int big = 0;
	q.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &q[i]);
		if(q[i]<=15000)
			big = max(q[i], big);
	}
	save.push_back(0);
	check[0] = true;
	func(0, big+500);

	for (int i = 0; i < n; i++) {
		if (q[i]>15000) printf("N ");
		else if (check[q[i]]) printf("Y ");
		else printf("N ");
	}
	return 0;
}