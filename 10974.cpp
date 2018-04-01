#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int num;
bool check[10];
void func(int n, vector<int>& v) {
	check[n] = true;
	v.push_back(n);
	for (int i = 1; i <= num; i++) {
		if (!check[i])  func(i, v);
	}
	if (v.size() == num) {
		for (int k : v) {
			printf("%d ", k);
		}
		printf("\n");
	}
	check[n] = false;
	v.pop_back();
}
int main() {
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		vector<int> v;
		func(i, v);
	}


	return 0;
}