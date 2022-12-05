#include <iostream>
using namespace std;

void buble_Sort(int a[], int size){
    int i, j, temp;
    for (i = 0; i<size-1;i++){
        for (j=0;j<size-i-1;j++){
            if (a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }

    }
}

void display(int a[], int size){
    for (int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int a[] = {14, 27, 95, 12, 26, 5, 33, 15, 9, 99};
    int n = sizeof(a)/sizeof(a[0]); 
    buble_Sort(a,n);
    cout<<"The sorted array: "<<endl;
    display(a,n);
    return 0;
}