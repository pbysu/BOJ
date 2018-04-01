#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
 
int dist[101][101];
int n, m;
int a, b;
int main() {
    scanf("%d %d ", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
            if (i == j)
                dist[i][j] = 0;
        }
    }
    while (m--) {
        scanf("%d %d", &a, &b);
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    int ans = INF;
    int temp = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dist[i][k] == INF) continue;
         
            for (int j = 1; j <= n; j++) {
 
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    int x;
    for (int i = 1; i <= n; i++) {
        temp = 0;
        for (int j = 1; j <= n; j++) {
            temp += dist[i][j];
            if (dist[i][j] == INF) break;
         
        }
        if (ans > temp) {
            ans = temp;
            x = i;
        }
    }
    printf("%d", x);
    return 0;
}