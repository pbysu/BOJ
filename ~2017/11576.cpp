#include<iostream>
#include<string>
#include<stack>
#include <math.h> 


using namespace std;

long long arr[30];
stack<long long> x;

int main() {

	int n, m;
	cin >> n>> m;
	int s;
	cin >> s;
	long long ans = 0;

	for (int i = 0; i < s; i++) {
		scanf("%lld", &arr[i]);
		ans += arr[i] * pow(n, s-i-1);
	}


	while (true){
		x.push(ans%m);
		ans = ans / m;
		if (ans < m) {
			x.push(ans);
			break;
		}
	}
	while (!x.empty()) {
		printf("%lld ", x.top());
		x.pop();
		m *= m;
	}
}