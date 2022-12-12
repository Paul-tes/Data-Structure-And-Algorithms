#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int  maxSubsequenceSum( int a[ ], int n){
     int seqStart = 0;
     int seqEnd = -1;
     int maxSum = 0;

   for( int i = 0; i < n; i++ ){
         int thisSum = 0;
         for( int j = i; j < n; j++ ){
                thisSum += a[ j ];
                if( thisSum > maxSum ){
                   maxSum = thisSum;
                   seqStart = i;
                   seqEnd = j ;
               }
          }
     }
     return maxSum;
}

int main(){
    int n;
    cout << "write size of array: ";
    cin>> n;
    int arr[n];
    int _noNegative = n / 4;
    int _noPosetive = n - _noNegative;
bool is;
    for (int i = 0; i < n; i++) {

        do{
                is =false;
            int x;
            cin >> x;
            if(x>0 && _noPosetive>0){
                    _noPosetive--;
              arr[i] = x;
            }else if(x<0 && _noNegative>0){
                arr[i] = x;
            _noNegative--;
            }else{
            is = true;
            if(_noNegative<=0)cout << "\n negative Number is Maximum please enter positive number\n";
            if(_noPosetive<=0)cout <<"\n positive Number is Maximum please Enter negative number\n";
            }
        }while(is);

    }is =false;
    cout  <<  maxSubsequenceSum(arr , n);
    return 0;
}
