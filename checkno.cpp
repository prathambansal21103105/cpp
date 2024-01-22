#include<iostream>
using namespace std;
bool checkNumber(int input[],int n,int x){
    if(n==1){
        if(input[n-1]==x){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        bool test;
        if(input[n-1]==x){
            test=true;
        }
        else{
            test=false;
        }
        return test or checkNumber(input,n-1,x);
    }
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int x;
    cin>>x;
    if(checkNumber(input,n,x)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}