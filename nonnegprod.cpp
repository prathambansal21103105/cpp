#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int input[n];
        countneg=0;
        countzero=0;
        for(int i=0;i<n;i++){
            cin>>input[i];
            if(input[i]<0){
                countneg+=1;
            }
            if(input[i]==0){
                countzero+=1;
            }
        }
        if(countzero!=0){
            cout<<0<<endl;
        }
        elif(countneg==0){
            cout<<0<<endl;
        }
        elif(countneg%2==0){
            cout<<0<<endl;
        }
        else{
            cout<<1<<endl;
        }

        t-=1;
    }
    return 0;
}