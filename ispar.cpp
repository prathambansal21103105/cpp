#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        long long n,k;
        cin>>n>>k;
        if(k==1){
            if (n%2==0){
                cout<<"even"<<endl;
            }
            else{
                cout<<"odd"<<endl;
            }
        }
        else if(k==2){
            cout<<"odd"<<endl;
        }
        else{
            cout<<"even"<<endl;
        }
        t-=1;
    }
    return 0;
}