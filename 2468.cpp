#include <iostream>
#include <cstring>
using namespace std;

int arr[102][102];
int visited[102][102];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N;
int maxh = 0; int minh = 101;
int cnt = 0; int res = 0;

void dfs(int x, int y) {

   for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if (visited[nx][ny] == -1 && arr[nx][ny] > maxh && nx > 0
		  && ny > 0 && nx <= N && ny <= N) {
		  visited[nx][ny] = 1;
		  dfs(nx, ny);
      }
	  
   }
}

int main() {
   scanf("%d", &N);
   
   for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
         scanf("%d", &arr[i][j]);

         if (arr[i][j] > maxh)
            maxh = arr[i][j];
         if (arr[i][j] < minh)
            minh = arr[i][j];
      }
   }

   if (maxh == minh) {
      cout << "1" << endl;
      return 0;
   }

   memset(visited, -1, sizeof(visited));

   while (maxh != 0) {
      for (int i = 1; i <= N; i++) {
         for (int j = 1; j <= N; j++) {
            if (arr[i][j] > maxh && visited[i][j] == -1) {
				visited[i][j] = 1;
               dfs(i, j);
               cnt++;
            }
         }
      }
      if (cnt > res) {
         res = cnt;
      }
      cnt = 0;
      maxh--;
      memset(visited, -1, sizeof(visited));
   }

   printf("%d\n", res);
   return 0;
}