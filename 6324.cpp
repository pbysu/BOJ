#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
int main() {

	scanf("%d", &n);
	char address[100];
	char *chptr;
	for (int tc = 1; tc <= n; tc++) {
		printf("URL #%d\n", tc);
		scanf("%s", address);

		chptr = strtok(address, ":");
		printf("Protocol = ");
		if (chptr == NULL) {
			printf("<default>\n");
		}
		else
			printf("%s\n", chptr);



		int siz = strlen(address);
		bool jd = false;
		for (int i = siz+3; i < 100; i++) {
			if (address[i] == '/')
				break;
			if (address[i] == ':') {
				jd = true;
			}
		}
		if (jd == true) {
			chptr = strtok(NULL, ":");
			printf("Host     = ");
			printf("%s\n", chptr + 2);
			chptr = strtok(NULL, "/");

			printf("Port     = ");
			if (!chptr)printf("<default>\n");
			else printf("%s\n", chptr);

		}
		else {
			chptr = strtok(NULL, "/");
			printf("Host     = ");
			printf("%s\n", chptr);
			printf("Port     = ", chptr);
			printf("<default>\n");
		}
		chptr = strtok(NULL, " ");
		printf("Path     = ");
		if (chptr == NULL) {
			printf("<default>\n");
		}
		else printf("%s\n", chptr);
		if (tc != n)printf("\n");
	}
	return 0;
}