#include<cstdio>
using namespace std;

int n;

struct Pos {
	int x;
	int y;
	Pos(int x, int y) :x(x), y(y) {}
	Pos() { x = y = 0; }
}pos[100001];

template<typename t>
void swap(t& a, t& b) {
	t tt = a;
	a = b;
	b = tt;
}

template<typename t>
void quick(t arr[], int left, int right, bool(*compare)(t a, t b)) {
	int lidx = left;
	int ridx = right;
	t pivot = arr[(left + right) >> 1];

	while (lidx <= ridx) {
		while (compare(arr[lidx], pivot)) 
			lidx++;
		while (compare(pivot, arr[ridx]))
			ridx--;

		if (lidx <= ridx) {
			swap(arr[lidx], arr[ridx]);
			lidx++;
			ridx--;
		}
	}

	if (lidx < right) quick(arr, lidx, right, compare);
	if (left < ridx) quick(arr, left, ridx, compare);
}

bool check(Pos p, Pos q) {
	if (p.y != q.y) {
		return p.y < q.y;
	}
	else {
		return p.x < q.x;
	}
}


int main() {
	scanf("%d", &n);
	for (int x,y, i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		pos[i] = Pos(x, y);
	}

	quick(pos, 0, n - 1, check);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", pos[i].x, pos[i].y);
	}

}