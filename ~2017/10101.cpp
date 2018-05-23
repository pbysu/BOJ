#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int num[3];
int total;
map<int, int> ma;
int main() {
	for (int tmp,i = 0; i < 3; i++) {
		scanf("%d", &tmp);
		total += tmp;
		ma[tmp]++;
	}
	if (total != 180)
		cout << "Error";
	else {
		if (ma.size() == 1)
			cout << "Equilateral";
		else if (ma.size() == 2)
			cout << "Isosceles";
		else
			cout << "Scalene";
	}
	return 0;
}