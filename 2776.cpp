#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int arr1[1000100];
int arr2[1000100];

int main() {
	int note;
	int cnt1;
	int cnt2;

	scanf("%d", &note);

	while (note > 0)
	{
		scanf("%d", &cnt1);

		for (int i = 0; i < cnt1; i++) {
			scanf("%d", &arr1[i]);
		}

		scanf("%d", &cnt2);

		for (int i = 0; i < cnt2; i++) {
			scanf("%d", &arr2[i]);
		}

		bool check;
		sort(arr1, arr1 + cnt1);

		for (int i = 0; i < cnt2; i++) {
			check = binary_search(arr1, arr1 + cnt1, arr2[i]);
			if (check == true) printf("1\n");
			else printf("0\n");
		}
		note--;
	}
}