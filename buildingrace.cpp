#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        float a,b,x,y;
        cin>>a>>b>>x>>y;
        float s1=a/x;
        float s2=b/y;
        if(s1>s2){
            cout<<"Chefina"<<endl;
        }
        else if(s2>s1){
            cout<<"Chef"<<endl;
        }
        else{
            cout<<"Both"<<endl;
        }
        t-=1;
    }
    return 0;
}