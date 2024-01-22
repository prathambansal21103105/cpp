#include<iostream>
using namespace std;
int main(){
    int a[10];
    a[0]=5;
    cout<<a<<endl;     // we get the same output for both which tells us that a is simply the address of the first element of array a 
    cout<<&a[0]<<endl;
    cout<<&a<<endl;   // here we print the address of array a which is same as the address of first element of a. it doesn't have any seperate memory stored
    cout<<*a<<endl;
    a[1]=3;
    cout<<*(a+1)<<endl; // *(a+i) gives us the ith element of array a or simply we can write a[i]
    int* r=&a[0];
    cout<<sizeof(a)<<endl; // here we get different outputs because sizeof(a) gives the size of the whole array whereas sizeof(r) gives the size of the pointer which is 8
    cout<<sizeof(r)<<endl;
    cout<<&r<<endl;       // here we are printing the address of r which is given seperate 8 bytes
    return 0;
}