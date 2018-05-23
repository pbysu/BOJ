#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
string str;
vector<string>v;

char c;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		str += c;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string tmp;
		string ttmp;
		string rtmp;
		for (int i = 0; i < n; i++) {
			cin >> c;
			tmp += c;
		}
		ttmp = tmp+tmp;
		if (ttmp.find(str) != string::npos) {
			v.push_back(tmp);
			continue;
		}
		rtmp = tmp;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == '1') rtmp[i] = '3';
			else if (tmp[i] == '2') rtmp[i] = '4';
			else if (tmp[i] == '3') rtmp[i] = '1';
			else if (tmp[i] == '4') rtmp[i] = '2';
		}
		reverse(rtmp.begin(), rtmp.end());
		rtmp += rtmp;
		 if (rtmp.find(str) != string::npos) {
			v.push_back(tmp);
		}
	}

	printf("%d\n", v.size());

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << (char)v[i][j]<<' ';
		}
		cout << "\n";
	}

	return 0;
}