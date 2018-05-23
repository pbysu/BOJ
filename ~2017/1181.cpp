#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int tc;
vector<string> v;

int main() {

	scanf("%d", &tc);
	string str;
	while (tc--) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), [](string p, string q) {
		if (p.size() != q.size())
			return p.size() < q.size();
		return p < q;
	}
	);

	vector<string>::iterator it = unique(v.begin(), v.end());

	v.erase(it, v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}