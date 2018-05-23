#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1002][1002];
int dp[1002][1002];

int main() {
   ios::sync_with_stdio(false);
   int n, m, mx = 0;
   string str;
   cin >> n>>m;
   for (int i = 0; i < n; i++) {
      cin >> str;
      for (int j = 0; j < m; j++)arr[i+1][j+1] = str[j]-48;
   }

   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (arr[i][j] == 1) dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
         if (mx < dp[i][j])mx = dp[i][j];
      }
   }
   printf("%d\n", mx*mx);
   return 0;
}