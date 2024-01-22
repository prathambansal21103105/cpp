#include<iostream>
using namespace std;

void g(int const& a){
    // a++; this is not possible because we took a const reference of the variable now the path becomes read only
}
void f(const int* p){
    // (*p)++; now we can't change it because we took a const copy of the pointer so the new path is read only
}
int main(){
    int const i=10; //now this path is read only

    //int* p=&i; address of a const int can't be stored in a normal pointer

    int const* p=&i; //this path is also read only

    int j=12;
    int* p3=&j;
    f(p3);
    cout<<j<<endl;

    int const* p2=&j; //this is possible because new paths can be read only no matter what is the main path
    cout<<*p2<<endl;
    j++;
    cout<<*p2<<endl;
    return 0;
}