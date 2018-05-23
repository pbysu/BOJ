#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int main() {
	string a;
	cin >> a;
	reverse(begin(a), end(a));
	int j = 0;
	int total = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == 'A') {
			total += 10 * pow(16, j);
			j++;
		}
		else if (a[i] == 'B') {
			total += 11*pow(16, j);
			j++;
		}
		else if (a[i] == 'C') {
			total += 12 * pow(16, j);
			j++;
		}
		else if (a[i] == 'D') {
			total += 13 * pow(16, j);
			j++;
		}
		else if (a[i] == 'E') {
			total += 14 * pow(16, j);
			j++;
		}
		else if (a[i] == 'F') {
			total += 15 * pow(16, j);
			j++;
		}
		else {
			total += (a[i] - '0')*pow(16, j);
			j++;
		}
	}
	printf("%d", total);
	return 0;
}