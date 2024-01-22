#include<iostream>
using namespace std;
int main(){

    int a,b;
    cout<<"Enter two numbers of your choice"<<endl;
    cin>>a>>b;

    char op;
    cout<<"Enter an operator"<<endl;
    cin>>op;

    switch(op){
        case '+':
        cout<<a+b<<endl;
        break;
        case '-':
        cout<<a-b<<endl;
        break;
        case '*':
        cout<<a*b<<endl;
        break;
        case '/':
        cout<<a/b<<endl;
        break;
        default:
        cout<<"I am still learming more"<<endl;

    }





    return 0;
}