#include<iostream>
#include<math.h>
#include<string>
using namespace std;
string ns;
string nf;
string ms;
string mf;
int main() {
	cin >> ns>> ms;
	int nSize = ns.length();
	nf = ns;
	mf = ms;
	for (int i = 0; i < nSize; i++) {
		if (ns[i] == '5' || ns[i] == '6') {
			ns[i] = '6';
			nf[i] = '5';
		}
	}
	int mSize = ms.length();
	for (int i = 0; i < mSize; i++) {
		if (ms[i] == '5' || ms[i] == '6') {
			ms[i] = '6';
			mf[i] = '5';
		}
	}
	int nma=0;
	int nmi = 0;
	int mma = 0;
	int mmi = 0;
	int ten = 1;
	for (int i = nSize-1; i >= 0; i--) {
		nma+=(ns[i] - '0')*ten;
		nmi += (nf[i] - '0')*ten;
		ten *= 10;
	}
	ten = 1;
	for (int i = mSize - 1; i >= 0; i--) {
		mma += (ms[i] - '0')*ten;
		mmi += (mf[i] - '0')*ten;
		ten *= 10;
	}
	printf("%d %d", mmi + nmi, mma + nma);
	return 0;
}