#include<iostream>
using namespace std;
int a;           //we shouldn't use global variables 
void g(){
    a++;
    cout<<a<<endl;
}
void f(){
    cout<<a<<endl;
    a++;
    g();
}
int main(){            
    a=10;                  
    f();
    f();
    cout<<a<<endl;
    return 0;
}