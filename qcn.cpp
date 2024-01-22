#include<iostream>
using namespace std;
int main(){
    char a;
    cin>>a;
    int asc;
    asc=a;
    if (asc>=97 and asc<=122){
        cout<<0;
    }
    else if (asc>=65 and asc<=90){
        cout<<1;
    }
    else{
        cout<<-1;
    }
    return 0;
}