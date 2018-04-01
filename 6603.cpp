#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int k, temp;
vector<string> v;

void function(int idx, string str, int cnt) {

	if (cnt > 6) return;

	if (cnt == 6) {
		cout << str << endl;
		return;
	}

	for (int i = idx+1; i < k; i++) {
		function(i, str +" " +v[i], cnt + 1);
	}

}

int main() {

	while (true) {
		cin >> k;

		if (k == 0)break;

		v.resize(k);

		for (int i = 0; i < k; i++) {
			cin >> v[i];
		}

		for (int i = 0; i < k-5; i++) {
			 function(i,v[i],1);
		}
		cout << endl;
	}

	return 0;
}