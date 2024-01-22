#include<iostream>
using namespace std;
void increment(int& n){
    n++;
}
int main(){
    int i;
    i=10;
    increment(i);  //we are passing by refrence instead of pass by value  
    cout<<i<<endl;
    return 0;
}