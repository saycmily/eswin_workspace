#include <stdio.h>
int main( ) {
 
   int fenqu[48] = {131072, 262144, 262144,
                    65536, 65536, 262144, 262144,
                    262144, 262144, 262144, 262144,
                    65536, 65536, 196608,
                    196608, 4194304, 4194304,
                    131072, 131072, 65536, 65536,
                    196608, 196608
                     };//1441792
   int sum, i;
   for(i = 0; i < 23; i++){
      printf("%d\n", fenqu[i]);
      sum += fenqu[i] / 1024;
   }
   printf( "\nYou entered: %d ", sum);
   printf("\n");
   return 0;
}