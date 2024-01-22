#include<iostream>
using namespace std;
int main(){

    int n;
    cin>>n;

    int j;

    int i;

    for(j=2;j<n;j++){
    
    for(i=2;i<j;i++){
        if(j%i==0){
            break;
        }
    }
    if(j==i){
        cout<<j<<endl;
    }
    }



    return 0;
}