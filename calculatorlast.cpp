#include<iostream>
using namespace std;
int main(){
    int a;
    int b;
    cout<<"Please give two numbers"<<endl;
    cin>>a>>b;

    char op;
    cout<<"Please give an operator"<<endl;
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
        cout<<"Please choose another operator"<<endl;
        break;

    }







    return 0;
}