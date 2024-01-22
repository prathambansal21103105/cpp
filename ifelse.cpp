#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if (a>b){
        if(a>c){
        cout<<"a\n";
        cout<<a<<endl;
    }else{
        cout<<"c\n";
        cout<<c<<endl;
    }
    }else{
        if(b>c){
            cout<<"b\n";
            cout<<b<<endl;
        }else{
            cout<<"c\n";
            cout<<c<<endl;
        }
    }






    return 0;
}