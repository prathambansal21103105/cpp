#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (j>=n-i+2){
                cout<<"*";
            }
            else{
                cout<<j;
            }
        }
        for(int k=n;k>=1;k--){
            if(k>=n-i+2){
                cout<<"*";
            }
            else{
                cout<<k;
            }
        }
        cout<<endl;
    }
    return 0;
}