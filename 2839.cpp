#include<iostream>
 
using namespace std;
int kg;
int five;
int three = 0;
 
int main() {
 
    scanf("%d", &kg); 
    five = kg / 5;
    while (true) {
        if ((kg - five* 5) % 3 == 0) {
            three = (kg - five * 5) / 3;
            break;
        }
        else five=five-1;
 
        if (five == -1) {
            three =-1;
            five = 0;
            break;
        }
    }
    printf("%d\n", five + three);
 
    return 0;
}