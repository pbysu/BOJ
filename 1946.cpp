#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
 
using namespace std;
int lank[100000];
bool check[100000];
int main() {
    int tc;
    int n=0;
    int ans;
    int temp;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        scanf("%d", &n);
         
        ans = 1;
        for (int j = 0; j < n; j++) {
            scanf("%d", &temp);
            --temp;
            scanf("%d", &lank[temp]);
        }
        int min = lank[0];
 
        for (int j = 1; j < n; j++) {
            if (min > lank[j]) {
                min = lank[j];
                ans++;
            }
        }
        memset(check, false, n);
        printf("%d\n", ans);
         
    }
 
    return 0;
}