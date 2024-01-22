#include<iostream>
using namespace std;
int main(){
    int i=10;
    int *p=&i;
    cout<<p<<endl;
    p=p+1;
    cout<<p<<endl; //when we do +1 then it adds 4 to the hexadecimal number
    return 0; //in case of a double pointer +1 adds 8 
}