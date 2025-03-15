
#include<iostream>
using namespace std;
int main(){

    int a = 1;
    int *ptr = &a;

    cout<<"Before"<<endl;
    cout<<" F : "<<a<<endl;
    cout <<" *Ptr : "<<*ptr<<endl;
    cout<<"After\n";
    *ptr  = 9;
    cout<<" F : "<<a<<endl;
    cout <<" *Ptr : "<<*ptr<<endl;
    delete ptr;
    ptr  = NULL;
    
}
