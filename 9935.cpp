#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
stack<char> fs, ls, ms;
char fin[40];
int main() {
	ls.push('\n');
	char tmp;
	while (1) {
		scanf("%c", &tmp);
		if (tmp == '\n') break;
		fs.push(tmp);
	}
	scanf("%s", &fin);
	int fsiz = strlen(fin);
	int idx;
	while (!fs.empty()) {
		idx = 1;
		if (fs.top() != fin[0]) ls.push(fs.top()), fs.pop();
		else {
			ms.push(fs.top()), fs.pop();
			while (idx != fsiz) {
				if (ls.top() == fin[idx++]) {
					ms.push(ls.top()), ls.pop();
				}
				else {
					while (!ms.empty()) {
						ls.push(ms.top()), ms.pop();
					}
					break;
				}
			}
			while (!ms.empty()) {
				ms.pop();
			}
		}
	}
	if (ls.size() == 1)
		printf("FRULA");
	else
		while (!ls.empty())
			printf("%c", ls.top()), ls.pop();
	return 0;
}