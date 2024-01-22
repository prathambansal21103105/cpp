#include<iostream>
using namespace std;
int main(){
    int i=10;
    int* p=&i;        //when we increse the value of p by 1 it shifts 4 bytes in address and starts pointing to a different integer
    cout<<p<<endl;    // if we add 2 then it shifts 8 bytes.
    p=p+1;            // in an array p=p+i points to the ith index.
    cout<<p<<endl;    // if p points to address of a double so p=p+1 will shift p to 8 bytes because size of a double is 8 bytes.
    return 0;
}