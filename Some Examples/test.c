#include <stdio.h>

int x = 0;
int zip(){
   x++;
   return x;
}









int main(){
   int w = zip();
   int y =1;
   y /= 2;
   printf("%d\n",w);
   
}