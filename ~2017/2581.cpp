#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
bool arr[10001];
using namespace std;

int main()
{
	arr[1] = true;
	
	for (int i = 2; i < 10001; i++) {
		if (arr[i] == false) {
			for (int j = i+1; j < 10001; j++) {
				if (j%i == 0)
					arr[j] = true;
			}
		}
	}
	int st;
	int end;
	scanf("%d\n %d", &st, &end);
	int jd = 0;
	int total = 0;
	int min = 0;
	for (int i = st; i <= end; i++) {
		if (arr[i] == false) {
			jd++;
			total += i;
			if (jd == 1) {
				min = i;
			}
		}
	}
	if (jd == 0) {
		printf("-1");
	}
	else{
		printf("%d \n%d", total, min);
	}

}