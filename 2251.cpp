#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

set<int> ans;
set<int>::iterator it;
int a, b, c;
int k;
bool visited[201][201][201];


void func(int ta, int tb, int tc) {

	if (ta > a || tb > b || tc > c
		|| ta < 0 || tb < 0 || tc < 0)
		return;

	if (visited[ta][tb][tc] == true)
		return;

	visited[ta][tb][tc] = true;



	if (ta == 0)
		ans.insert(tc);


	int temp = ta + tc - a;
	if (temp < 0)	 temp = 0;

	func(ta + tc - temp, tb, temp);

	temp = tb + tc - b;
	if (temp < 0)	 temp = 0;
	func(ta, tb + tc - temp, temp);
	//c->x 에 넣는다


	temp = tc + ta - c;
	if (temp < 0)	 temp = 0;
	func(temp, tb, tc + ta - temp);

	temp = tc + tb - c;
	if (temp < 0)	 temp = 0;

	func(ta, temp, tc + tb - temp);
	// x-> c 에 넣는다

	temp = ta + tb - a;
	if (temp < 0)	 temp = 0;

	func(ta + tb - temp, temp, tc);

	temp = ta + tb - b;
	if (temp < 0)	 temp = 0;

	func(temp, ta + tb - temp, tc);


}
int main() {

	scanf("%d %d %d", &a, &b, &c);

	func(0, 0, c);

	for (it = ans.begin(); it != ans.end(); it++) {
		printf("%d ", *it);
	}
	return 0;
}