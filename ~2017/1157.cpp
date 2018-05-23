#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int arr[26];
 
int main() {
    string s1;
    cin >> s1;
    int num = 0;
    int sizen = 0;
    int Sizen = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] / 'a' == 0) {
            num = s1[i]%'A';
            arr[num]++;
            sizen++;
        }
        else{
            num = s1[i] % 'a';
            arr[num]++;
            sizen++;
        }
    }
    int x = 0;
    for (int i = 1; i < 26; i++) {
        x = arr[i] > arr[x] ? i : x;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[x] == arr[i]&&x!=i) {
            x = -1;
            cout << "?";
            break;
        }
    }
    if (x != -1)
        printf("%c", x + 'A');
 
}