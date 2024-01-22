#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    cout<<"The required pattern--"<<endl;
    for (int i=0;i<=n;i++){
        for (int j=1;j<=n-i;j++){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}    


