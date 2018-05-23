#include<iostream>
#include<algorithm>
using namespace std;

char map[27][3];
int n;
int temp = 0;
void post_func(int ypos, int xpos) {
	if (map[ypos][xpos] == NULL) return;

	printf("%c", ypos+'A');
	if (map[ypos][0] != '.') {
		post_func(map[ypos][0] - 'A', 0);
	}
	if (map[ypos][1] != '.') {
		post_func(map[ypos][1] - 'A', 0);
	}
}


void inner_func(int ypos) {
	if (map[ypos][0] == NULL) return;
	if (map[ypos][0] != '.') {
		inner_func(map[ypos][0] - 'A');
	}
	printf("%c", ypos + 'A');
	if (map[ypos][1] != '.') {
		inner_func(map[ypos][1] - 'A');
	}
}

void last_func(int ypos) {
	if (map[ypos][0] == NULL) return;

	if (map[ypos][0] != '.') {
		last_func(map[ypos][0] - 'A');

	}
	if (map[ypos][1] != '.') {
		last_func(map[ypos][1] - 'A');
	}
	printf("%c", ypos + 'A');
}

int a, b, c;
int main() {
	scanf("%d", &n);
	getchar();

	for (int i = 1; i <= n; i++) {
		scanf("%c %c %c", &a, &b, &c);
		map[a - 'A'][0] = b;
		map[a - 'A'][1] = c;
		getchar();
	}
	post_func(0, 0);
	printf("\n");
	inner_func(0);
	printf("\n");
	last_func(0);

	return 0;
}