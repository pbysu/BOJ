#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> v;
int main() {
	int num;
	int cnt = 0;
	scanf("%d", &num);
	int siz;
	while (true) {
		while (true) {
			v.push_back(num % 10);
			num /= 10;
			if (num == 0) break;
		}
		siz= v.size();
		for (int i = 0; i < v.size() - 1; i++) {
			v[i + 1] += v[i] / 10;
			if (v[i]%10 >= 5) v[i + 1]++;
			cnt++;
		}
		num = v[siz - 1];
		if (v[siz-1] / 10 == 0)break;
		v.clear();
	}
	printf("%d", v[siz - 1]);
	while (cnt--) printf("0");
	
	return 0;
}