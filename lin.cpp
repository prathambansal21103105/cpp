#include<iostream>
using namespace std;
int lastIndex(int input[],int n, int x){
    if(n==1){
        if(input[0]==x){
            return 0;
        }
        else{
            return -1;
        }
    }
    else{
        int test;
        if(input[n-1]==x){
            test=n-1;
            return test;
        }
        else{
            test=-1;
            return lastIndex(input,n-1,x);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cout<<lastIndex(input,n,x)<<endl;
    return 0;
}