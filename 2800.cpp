#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
#include<set>	
using namespace std;
priority_queue<string,vector<string>, greater<string> > pq;
stack<pair<char, int>> st, ex;
vector<pair<int, int>> save;
set<string> strSet;
string str;
char tmp;
pair<char, int> cur;
int idx;
void func(string tst, int idx, int k) {
	if (idx == save.size())
		return;
	if (idx== save.size()) {
		if (tst == str)
			return;
	}

	string tmpst = tst;
	char ttt = '$';
	tmpst.replace(save[idx].first,1, "$");
	tmpst.replace(save[idx].second,1, "$");
	func(tst, idx + 1, k);
	func(tmpst, idx + 1, k+1);
	string saveStr = "";
	for (int i = 0; i < tmpst.length(); i++) {
		if (tmpst[i] == '$')continue;
		saveStr += tmpst[i];
	}
	if (strSet.find(saveStr) == strSet.end()) {
		pq.push(saveStr);
		strSet.insert(saveStr);
	}

}
int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		st.push({ str[i], i });
	}
	while (!st.empty()) {
		cur = st.top();
		st.pop();
		if (cur.first == '(') {
			save.push_back({ cur.second,ex.top().second });
			ex.pop();
		}
		else if (cur.first == ')') {
			ex.push( cur);
			continue;
		}
		else {
			continue;
		}
	}
	sort(save.begin(), save.end(), [](pair<int, int> p, pair<int, int> q) {
		if (p.second != q.second) {
			return p.second > q.second;
		}
	});
	func(str, 0,1);

	while (!pq.empty()) {
		cout << pq.top();
		printf("\n");
		pq.pop();
	}
	return 0;
}