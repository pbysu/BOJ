#include<iostream>
#include<queue>
#include <algorithm>
 
using namespace std;
priority_queue <int> qmax;
int s[1001];
 
int main() {
    int n;
    int me;
    int first;
    int temp;
    scanf("%d", &n);
    scanf("%d", &me);
    first = me;
    n--;
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        qmax.push(temp);
    }
 
    if (n != 0) {
        while (qmax.top() >= me) {
            me++;
            temp = qmax.top();
            qmax.pop();
            qmax.push(temp - 1);
        }
    }
 
 
    printf("%d", me - first);
    return 0;
}