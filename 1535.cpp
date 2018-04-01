#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;
vector<int> happy;
vector<int> sad;

int func(int pos,int life, int val) {
	int ret = 0;
	if (life > 100)
		return val;
	else if (pos >= n)
		return val;
	ret= max(ret,func(pos + 1, life, val));
	if(life+sad[pos]<100)
		ret = max(ret, func(pos + 1, life + sad[pos], val + happy[pos]));
	return ret;
}

int main() {
	scanf("%d", &n);
	happy.resize(n);
	sad.resize(n);

	
	for (int i = 0; i < n; i++) {
		scanf("%d", &sad[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &happy[i]);
	}
	printf("%d", func(0, 0, 0));
	return 0;
}