#include<iostream>
#include<string.h>
#include <string>

using namespace std;

int arr[100][2];
char num[100][3];
int main(){
 
   int tc;
   scanf("%d", &tc);
   bool jd = true;
   for (int i = 0; i < tc; i++){
      scanf("%s %d %d", &num[i], &arr[i][0], &arr[i][1]);
   }
   char check[3];
   int ch1, ch2;
   int ans = 0;
   for (int i = 100; i < 1000; i++){
      jd = true;
      check[0] = i / 100 + '0';
      check[1] = (i / 10) % 10 + '0';
      check[2] = i % 10 + '0';
      if (check[0] == '0'||check[1]=='0'||check[2]=='0')
         continue;
      if (check[0] == check[1] || check[0] == check[2] ||
         check[1] == check[2]){
         continue;
      }
      for (int j = 0; j < tc; j++){
         if (j!=0 && jd == false) break;
         ch1 = 0; ch2 = 0;
         for (int l = 0; l < 3; l++){
            for (int k = 0; k < 3; k++){
               if (num[j][l] == check[k] && l != k){
                  ch2++;
               }
               if (num[j][l] == check[k] && l == k){
                  ch1++;
               }
            }
         }
         if (jd == true && arr[j][0] == ch1 &&arr[j][1] == ch2){
            jd = true;
         }
         else {
            jd = false;
         }
      }
      if (jd == true)
         ans++;
   }

   printf("%d", ans);
   return 0;
}