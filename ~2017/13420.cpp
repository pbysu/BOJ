#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

int main() {
	int tc;
	ll num1, num2, ans;
	int garbage;
	char oper;
	ll realAns;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%lld %c %lld %c %lld",
			&num1, &oper, &num2, &garbage, &ans);

		switch (oper)
		{
		case'*':
			realAns = num1*num2;
			break;

		case '+':
			realAns = num1 + num2;
			break;

		case '-':
			realAns = num1 - num2;
			break;

		case '/':
			realAns = num1 / num2;
			break;
		}

		if (realAns == ans)
			printf("correct\n");

		else
			printf("wrong answer\n");

	}

	return 0;
}