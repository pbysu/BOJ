#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#define MAX(A,B) A>B? A:B
#define MIN(A,B) A>B? B:A
using namespace std;
int n, arr[101];
set<int> s;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	scanf("%d", &n);
	int minimum = 2e9;
	int maximum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		maximum = MAX(maximum, arr[i]);
		minimum = MIN(minimum, arr[i]);
	}

	int diff = maximum - minimum;

	for (int i = 1; i*i <= diff; i++) {
		if (diff%i == 0)
			s.insert(i), s.insert(diff / i);
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		bool jd = true;
		int t = arr[0] % *it;
		for (int i = 1; i < n; i++) {
			if (arr[i] % *it != t) {
				jd = false;
				break;
			}
		}
		if (*it!=1 &&jd)
			printf("%d ", *it);
	}
	return 0;
}