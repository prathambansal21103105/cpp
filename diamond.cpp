#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int r=int(n/2)+1;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=r-i;j++){
            cout<<" ";
        }
        for(int k=1;k<=2*(i)-1;k++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int l=int(n/2);l>=1;l--){
        for(int m=1;m<=r-l;m++){
            cout<<" ";
        }
        for(int n=1;n<=2*(l)-1;n++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}