#include<iostream>
#include<string>

using namespace std;
int n;
string front, back, tmp;

int main() {
	scanf("%d", &n);
	cin >> tmp;
	bool jd = false;
	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] == '*') {
			jd = true;
		}
		else if (jd) {
			back += tmp[i];
		}
		else
			front += tmp[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp.size()>= back.size() + front.size()&&tmp.substr(0, front.size()) == front && tmp.substr(tmp.size() - back.size(), back.size())==back) {
			printf("DA\n");
		}
		else
			printf("NE\n");
	}

	return 0;
}