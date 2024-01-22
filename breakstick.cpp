#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t>0){
    int n,x;
    cin>>n>>x;
    if (x%2!=0){
        cout<<"Yes"<<endl;
    }
    else{
        if (n%2==0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    t-=1;
    }
    return 0;
}