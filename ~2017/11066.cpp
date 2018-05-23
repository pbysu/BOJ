#include <bits/stdc++.h>
using namespace std;
 
int T, N;
int A[503], S[503];
int D[503][503], K[503][503];
 
int main()
{
    for (scanf("%d", &T);T--;){
        scanf("%d", &N);
        for (int i=1;i<=N;i++) scanf("%d", A+i), S[i] = S[i-1] + A[i];
        for (int i=1;i<=N;i++) D[i-1][i] = 0, K[i-1][i] = i;
        for (int d=2;d<=N;d++){
            // d = j-i
            for (int i=0;i+d<=N;i++){
                int j = i+d;
                D[i][j] = 2e9;
                for (int k=K[i][j-1];k<=K[i+1][j];k++){
                    int v = D[i][k] + D[k][j] + S[j] - S[i];
                    if (D[i][j] > v)
                        D[i][j] = v, K[i][j] = k;
                }
            }
        }
        printf("%d\n", D[0][N]);
    }
}


//출처: http://blog.myungwoo.kr/98 [PS 이야기]