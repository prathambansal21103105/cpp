#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        float a,b,c;
        cin>>a>>b>>c;
        float avg=(a+b)/2;
        if(avg>c){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        t-=1;
    }
    return 0;
}