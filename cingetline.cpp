#include<iostream>
using namespace std;
int main(){
    char c[100];
    cin.getline(c,100,'o');
    cout<<c<<endl;
    return 0;
}
// cingetline function actually takes three arguments
// cin.getline(string_name,len,delimiter)
// here delimiter is the char before which you require the string
// it stops storing values when the char is reached and stores values only occuring before it
// we can put delimeter as any char we want but if
// we do not use it, it has a default value '\n'.
