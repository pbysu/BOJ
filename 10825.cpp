#include<cstdio>
#include<cstring>

using namespace std;

template<typename T>
void swap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}
struct S {
	char name[12];
	int val1;
	int val2;
	int val3;
}s[100010];
int n;

void quick(S arr[], int left, int right, bool(*compare)(S p, S q)) {
	int lidx = left;
	int ridx = right;
	S pivot = arr[(left + right) >> 1];
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

bool check(S p, S q) {
	if (p.val1 != q.val1) return p.val1 > q.val1;
	if (p.val2 != q.val2) return p.val2 < q.val2;
	if (p.val3 != q.val3) return p.val3 > q.val3;
	int idx = 0;
	while (1) {
		int ch = p.name[idx];
		int ch1 = q.name[idx];

		if (ch==-1 &&ch == ch1)return ch < ch1;
		if (ch != ch1) {
			return ch < ch1;
		}
		idx++;
	}

}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d %d", &s[i].name, &s[i].val1,&s[i].val2, &s[i].val3);
	}

	quick(s, 0, n - 1, check);
	for (int i = 0; i < n; i++) {
		printf("%s\n", s[i].name);
	}
}