#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
using namespace std;
int main() {
	int h, m, s,t;
	int th, tm, ts;
	int time, time1;
	scanf("%d:%d:%d", &h, &m, &s);
	scanf("%d:%d:%d", &th, &tm, &ts);
	time = h * 3600 + m * 60 + s;
	time1 = th * 3600 + tm * 60 + ts;
	time = time1 - time;

	if (time < 0) {
		int temp = 60 * 60 * 24;
		t =temp + time;
	}
	else{
	t = time;
	}
	th = t / 3600;
	t = t % 3600;
	tm = t / 60;
	t = t % 60;
	ts = t;
	


	printf("%02d:%02d:%02d", th, tm, ts);
}