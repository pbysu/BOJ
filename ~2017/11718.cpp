#include<iostream>
#include<string>
using namespace std;

int arr[101][101];
int main() {
	int i = 0;
	string line;
	while (getline(cin, line)) {
		if (i == 100)
			break;
		cout << line << endl;
		i++;
	}
	return 0;
}