#include<iostream>
#include<string>

using namespace std;

string a;
string b;

int main() {
	int tc;			
	int total=0;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		cin >> a;
		cin >> b;
		total = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[j]) total++;
		}
		printf("Hamming distance is %d.\n", total);

	}
	return 0;
}