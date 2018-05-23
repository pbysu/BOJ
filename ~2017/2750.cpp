#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;


int main() {

	int n;
	int tmp;
	scanf("%d", &n);

	while (n--) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}