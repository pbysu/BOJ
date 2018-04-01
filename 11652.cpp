#include<iostream>
#include<string>
#include<algorithm>
 
using std::printf;
using std::sort;
using std::scanf;
 
struct card {
    long long n1=10002;
    int count = 0;
};
 
card x[1000001];
 
 
int main() {
 
 
    int t;
    long long temp;
    scanf("%d", &t);
    int k = 0;
 
 
    for (int i = 0; i < t; i++) {
        scanf("%lld", &temp);
        int judg;
 
        for (int j = 0; j < k||j==0; j++) {
            judg = 0;
            if (x[j].n1 == temp) {
                x[j].count++;
                judg = 1;
                break;
            }
        }
        if (judg != 1) {
            x[k].n1 = temp;
            x[k].count++;
            k++;
            judg = 0;
             
        }
 
    }
 
 
    for (int i = 0; i < k; i++) {
        if (x[0].count < x[i].count) {
            x[0] = x[i];
            }
        else if (x[0].count == x[i].count) {
            if (x[0].n1 > x[i].n1) {
                x[0] = x[i];
            }
        }
    }
    printf("%lld", x[0].n1);
}