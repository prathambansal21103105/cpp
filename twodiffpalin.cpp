#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int a,b;
        cin>>a>>b;
        if(a==1 or b==1){
            cout<<"NO"<<endl;
        }
        else if(a%2!=0 and b%2!=0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
        t-=1;
    }
    return 0;
}