#include <iostream>
using namespace std;

int  maxSubsequenceSum( int a[ ], int n){
     int seqStart = 0;
     int seqEnd = -1;
     int maxSum = 0;
     int thisSum = 0;

    for( int i = 0, j = 0; j < n; j++ ){
          thisSum += a [ j ] ;
          if( thisSum > maxSum ) {
               maxSum = thisSum;
               seqStart = i;
               seqEnd = j ;
          }else if ( thisSum < 0 ){
                i=j+1;
               thisSum = 0;
         }
     }

     return maxSum;
}

int main(){
    int a [] = {12, -5,  6,  -7,  8,  -1, 2};
    int n = sizeof(a) / sizeof(a[0]);

    cout  <<  maxSubsequenceSum(a, n);
    // excution time 0.003
    return 0;
}
