#include<iostream>
using namespace std;
int main(){

    int n1,n2;
    cin>>n1>>n2;

    for(int i=n1;i<=n2;i++){
        int j;
        for(j=2;j<i;j++){
            if(i%j==0){
                break;
            }
            
        }
        if(i==j){
            cout<<i<<endl;
        }
        
    }




    return 0;
}