#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        float a,b,x,y;
        cin>>a>>b>>x>>y;
        float sa=a/x;
        float sb=b/y;
        if(sa>sb){
            cout<<"ALICE"<<endl;
        }
        else if(sb>sa){
            cout<<"BOB"<<endl;
        }
        else{
            cout<<"EQUAL"<<endl;
        }
        t-=1;
    }
    return 0;
}