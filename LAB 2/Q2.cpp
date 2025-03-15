
#include<iostream>
using namespace std;

int maxValue(int a [], int l){
int max =0; 
 for ( int i = 0 ;i<l; i++){   
    if(a[i] >max ){    
        max = a[i];
    }
 }
 return max; 
}
int main(){

    int arr[5] = { 7,10,12,5,9};
    int result = maxValue(arr, 5);
    cout<<"Max Value : "<<result<<endl;
}
/*
Time Complexity

 f(n) = 1 + n + n + 1
 f(n)  = 2 + 2n
  removing constant
  f(n) = n

  Big-O(n)
*/

