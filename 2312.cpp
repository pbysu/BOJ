#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
bool PrimeArray[100010];
int arr[1010];

void Eratos(int n)
{
	for (int i = 2; i <= n; i++) PrimeArray[i] = true;
	for (int i = 2; (i*i) <= n; i++)
	{
		if (PrimeArray[i])
		{
			for (int j = i*i; j <= n; j += i) PrimeArray[j] = false;
		}
	}
	for (int i = 0; i <= n; i++) {
		if (PrimeArray[i]) {
			int temp = n;
			int cnt = 0;
			if(temp%i == 0){
			while (1) {
				temp = temp / i;
				cnt++;
				if (temp%i != 0)
					break;
			}
			printf("%d %d\n", i, cnt);
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		scanf("%d", &arr[i]);
		Eratos(arr[i]);
	}

}