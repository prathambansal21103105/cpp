#include<iostream>
using namespace std;
int main(){

    int r;
    cin>>r;


    for(int i=1;i<=r;i++){

        for(int j=1;j<=i;j++){

            int sum=i+j;
            
            if(sum%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }

        
        cout<<endl;
    }


    return 0;
}