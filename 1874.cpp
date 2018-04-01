#include<stack>
#include<iostream>
#include<queue>
 
using namespace std;
 
stack <int> s;
queue <char> q;
 
int main() {
    int tc;
    int n = 1;
    scanf("%d", &tc);
    int arr;
    int jd = 0;
    for (int i = 0; i < tc; i++) {
        scanf("%d", &arr);
        while (1) {
            if (s.empty()) {
                if (n > arr) {
                    jd = 1;
                    break;
                }
                s.push(n);
                n++;
                q.push('+');
            }
            else if (s.top() > arr) {
                s.pop();
                q.push('-');
            }
            else if (s.top() == arr) {
                s.pop();
                q.push('-');
                break;
            }
 
            else if (s.top() < arr) {
                if (n > arr) {
                    jd = 1;
                    break;
                }
                else {
                    s.push(n);
                    q.push('+');
                    n++;
                }
            }
 
        }
        if (jd == 1) break;
    }
 
    if (jd == 0) {
        while (!q.empty()) {
            printf("%c\n", q.front());
            q.pop();
        }
    }
    else
        printf("NO\n");
 
    return 0;
}