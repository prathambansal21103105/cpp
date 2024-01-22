#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        for(int i=n;i>=1;i--){
            cout<<i<<" ";
        }
        cout<<endl;
        t-=1;
    }
    return 0;
}