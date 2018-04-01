#include<iostream>
#include<algorithm>
#include<string>
 
using namespace std;
int arr1[1000100];
int arr2[1000100];
 
struct color {
    string name;
    int cost;
    long long mult;
};
color x[10];
int main() {
    int a = 1;
    for (int i = 0; i < 10; i++) {
        x[i].cost = i;
        x[i].mult = 1 * a;
        a = a * 10;
    }
    x[0].name = "black"; x[1].name = "brown"; x[2].name = "red"; x[3].name = "orange"; x[4].name = "yellow"; x[5].name = "green";
    x[6].name = "blue"; x[7].name = "violet"; x[8].name = "grey"; x[9].name = "white";
 
    string arr[3];
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    int num1, num2;
    long long num3;
    for (int i = 0; i < 10; i++) {
        if (x[i].name == arr[0]) {
            num1 = x[i].cost * 10;
        }
        if (x[i].name == arr[1])
            num2 = x[i].cost;
        if (x[i].name == arr[2])
            num3 = x[i].mult;
    }
    num3 = (num1 + num2)*num3;
 
    printf("%lld", num3);
}