#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            char a=64+i;
            cout<<a;
        }
        cout<<endl;
    }
    return 0;
}