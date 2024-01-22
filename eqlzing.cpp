#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int a,b;
        cin>>a>>b;
        int sub=a-b;
        if(sub%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        t-=1;
    }
    return 0;
}