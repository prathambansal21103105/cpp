#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3};
    char b[]="abc";
    cout<<a<<endl;
    cout<<b<<endl;
    char* c=&b[0];
    cout<<c<<endl;
    char c1='a';
    char* pc=&c1;   // when we print a char array it doesn't print the adress of the first element instead it prints the whole string
    cout<<c1<<endl;
    cout<<pc<<endl;  // when we print a character pointer instead of the address of the character it prints the character and that too till the point it doesn't find a null character
    return 0;
}