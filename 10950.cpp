#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int t; // 개수 ;


	cin >> t;

	int **padd = NULL;
	padd = new int*[2];
	for (int i = 0; i < t; i++)
	{

		padd[i] = new int[2];
		cin >> padd[i][0] >> padd[i][1];
		cout << padd[i][0] + padd[i][1] << endl;


	}

	return 0;

}