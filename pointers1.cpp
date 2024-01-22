#include<iostream>
using namespace std;
int main(){
    int i=10;
    int* p=&i;
    cout<<sizeof(p)<<endl;
    cout<<i<<endl;
    cout<<*p<<endl;
    i++;                   // *p tells the value stored at address p so it can be simply taken to be as an integer
    cout<<i<<endl;
    cout<<*p<<endl;
    int a=*p;
    a++;                  // size of pointer is usually 8
    cout<<a<<endl;
    cout<<*p<<endl;
    return 0;
}