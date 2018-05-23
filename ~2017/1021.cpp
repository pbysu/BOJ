#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

deque <int> num_deque;
deque <int> temp1;
deque <int> temp2;
int station[50];
int ans = 0;
int tc;
int tem1 = 0;
int tem2 = 0;

void temp1_fuc(int station_pos) {
	if (temp1.front() == station[station_pos]) {
		return;
	}
	temp1.push_front(temp1.back());
	temp1.pop_back();
	tem1++;
	return temp1_fuc(station_pos);
}

void temp2_fuc(int station_pos) {
	if (temp2.front() == station[station_pos]) {
		return;
	}
	temp2.push_back(temp2.front());
	temp2.pop_front();
	tem2++;
	return temp2_fuc(station_pos);
}
void func(int station_pos) {
	if (station_pos < tc) {
		if (num_deque.front() == station[station_pos]) {
			num_deque.pop_front();
			return func(station_pos+1);
		}
		else {
			temp1 = temp2 = num_deque;
			temp1_fuc(station_pos);
			temp2_fuc(station_pos);
			if (tem1 < tem2) {
				num_deque = temp1;
				ans+= tem1;
				tem1 =tem2 = 0;
				return func(station_pos);
			}
			else {
				num_deque = temp2;
				ans+= tem2;
				tem2 = 0;
				tem1 = 0;
				return func(station_pos);
			}
		}
	}
}



int main() {

	int size;
	scanf("%d %d", &size, &tc);
	for (int i = 1; i <= size; i++) {
		num_deque.push_back(i);
	}
	for (int i = 0; i < tc; i++) {
		scanf("%d", &station[i]);
	}
	func(0);

	printf("%d", ans);
	return 0;
}