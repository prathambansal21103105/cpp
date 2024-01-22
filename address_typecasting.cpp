#include<iostream>
using namespace std;
int main(){
    int i=65;
    char c=i;          //implicit typecasting
    cout<<c<<endl;

    int * p=&i;
    char * pc=(char*)p;  //explicit typecasting // here the char pointer also points to the integer but it would only read one byte
    cout<<p<<endl;
    cout<<pc<<endl;
    cout<<*p<<endl;
    cout<<*pc<<endl;
    cout<<*(pc+1)<<endl;
    cout<<*(pc+2)<<endl;
    cout<<*(pc+3)<<endl;
    return 0;
}