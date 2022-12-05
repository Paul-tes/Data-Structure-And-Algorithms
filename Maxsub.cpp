#include <iostream>;

void maxSubsequenceSum( const int a[ ], int n, int & seqStart, int & seqEnd, int & maxSum){
int thisSum = 0;
int maxSum = 0;
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
}


int main () {
    int sum = 0;
    int arr[] = {-5, 6, -7, 8 ,-1 ,2};
    maxSubsequenceSum(arr, 6, arr[0], arr[5], sum);
    std::cout << "sum = " << sum;
    return 0;
}
