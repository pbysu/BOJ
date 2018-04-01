#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char alpa[16];
int tc;

void function(int n,int m,int k, string x,int p, int q) {
	if (n == m) {
		if (p >= 1 && q >= 2) {
			cout << x << endl;
		}
	
	}
		
	else {
		for (int i = k; i < tc; i++) {
			if (alpa[i] == 'a' || alpa[i] == 'e' || alpa[i] == 'i' || alpa[i] == 'o' || alpa[i] == 'u')
			function(n + 1, m,i+1,x + alpa[i],p+1,q);
			else
				function(n + 1, m, i + 1, x + alpa[i], p, q+1);
		}
	}
}

int main() {
	int len;
	string x="";

	scanf("%d %d", &len, &tc);
	
	for (int i = 0; i < tc; i++) {
		cin >> alpa[i];
	}
	sort(alpa, alpa + tc);
	for (int i = 0; i < tc; i++) {
		if (alpa[i] == 'a' || alpa[i] == 'e' || alpa[i] == 'i' || alpa[i] == 'o' || alpa[i] == 'u')
			function(1, len, i + 1, x + alpa[i], 1, 0);
		else
			function(1, len, i + 1, x + alpa[i], 0, 1);
	}


	return 0;
}