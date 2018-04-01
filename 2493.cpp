#include<iostream>
#include<stack>	
#include<vector>


using namespace std;
vector<int> v;
stack<pair<int, int>> s;
stack<pair<int,int>> stemp;
int main() {
	int k, tmp;
	scanf("%d", &k);
	v.resize(k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &tmp);
		s.push({ tmp,i});
	}
	for (int i = 0; i < k; i++) {
			while (!stemp.empty() && stemp.top() <= s.top()) {
				v[stemp.top().second] = s.top().second;
				stemp.pop();
			}

			stemp.push(s.top());
			s.pop();
		}

	while(!stemp.empty()){
		v[stemp.top().second] = -1;
		stemp.pop();
	}

	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]+1);
	}


	return 0;
}