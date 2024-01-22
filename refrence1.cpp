#include<iostream>
using namespace std;
void increment(int &n){
    n++;
}
int& f(int n){
    int a=n;
    return a;
}
int* f2(){
    int i=10;
    return &i;
}

int main(){
    int i=10;
    int& j=i;
    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;
    int k=100;
    j=k;
    cout<<i<<endl;
    increment(i);
    cout<<i<<endl;
    // int& l=f(i);
    // cout<<l<<endl;       //we shouldn't return the reference or pointer of a local variable of a function
    // int*p=f2();          //because it would be lost after the function is used
    // cout<<p<<endl;
    return 0;
}