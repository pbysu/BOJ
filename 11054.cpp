#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>	 v;
vector<int> inclis;
vector<int> declis;
int save[1001][2];
int main() {
	int n;
	scanf("%d", &n);
	v.resize(n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	inclis.push_back(v[0]);
	declis.push_back(v[n-1]);
	save[0][0] = 1;
	save[n-1][1] = 1;
	
	for (int i = 1; i < n; i++) {
		if (v[i] > inclis.back()) {
			inclis.push_back(v[i]);
			save[i][0] = inclis.size();
		}
		else {
			vector<int>::iterator it = lower_bound(inclis.begin(), inclis.end(), v[i]);
			*it = v[i];
			save[i][0] = it - inclis.begin() + 1;
		}


		if (v[n-i] > declis.back()) {
			declis.push_back(v[n-i]);
			save[n-i][1] = declis.size();
		}
		else {
			vector<int>::iterator it = lower_bound(declis.begin(), declis.end(), v[n-i]);
			*it = v[n-i];
			save[n - i][1] = it - declis.begin() + 1;
		}

	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, save[i][0] + save[i][1]);
	}
	printf("%d", ans-1);
	return 0;
}