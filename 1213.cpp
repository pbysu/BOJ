#include<iostream>
#include<string>
using namespace std;
string a;

int arr[26];
int ans[50][2];

int main() {
	cin >> a;
	int size = a.length();
	int x = 0;
	char mid;
	bool just = false;
	bool jd = true;

	for (int i = 0; i < size; i++) {
		arr[a[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2 != 0 && just == true) {
			printf("I'm Sorry Hansoo");
			jd = false;
			break;
		}
		else if (arr[i] % 2 == 1 && just == false) {
			just = true;
			mid = 'A' + i;
			ans[x][0] = i;
			ans[x][1] = arr[i];
			x++;
		}

		else if (arr[i] != 0) {
			ans[x][0] = i;
			ans[x][1] = arr[i];
			x++;
		}
	}



	if (jd != false) {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < ans[i][1] / 2; j++) {
				printf("%c", 'A' + ans[i][0]);
			}
		}

		if (just == true)
			printf("%c", mid);

		for (int i = x - 1; i >= 0; i--) {
			for (int j = 0; j < ans[i][1] / 2; j++) {
				printf("%c", 'A' + ans[i][0]);
			}
		}
	}



	return 0;
}