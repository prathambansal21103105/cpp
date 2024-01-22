#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int r=65+n-i;r<=64+n;r++){
            char c=r;
            cout<<c;            
        }
        cout<<endl;
    }
    return 0;
}