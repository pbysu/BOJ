#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<iostream>
#include<string>
#include<algorithm>

using std::cin;
using std::printf;
using std::sort;
using std::scanf;
using std::string;
using std::cout;
using std::endl;


int main (){
	int s, m, h, t,ts=0,tm=0,th=0;
	scanf("%d %d %d", &h, &m, &s);
	scanf("%d", &t);
	th = t / 3600;
	t = t % 3600;
	tm = t / 60;
	t = t % 60;
	ts = t;

	if (ts + s >= 60) {
		int temp = ts + s;
		s = temp % 60;
		m += temp / 60;
	}
	else
		s = ts + s;


	if (tm + m >= 60) {
		int temp = tm + m;
		m = temp % 60;
		h += temp / 60;
	}
	else
		m = tm + m;

	if (th + h >= 24) {
		int temp = th + h;
		h = temp % 24;
	}
	else
		h = th + h;

	printf("%d %d %d", h, m, s);
}