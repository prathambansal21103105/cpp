#include<iostream>
using namespace std;
int multiplyNumbers(int m,int n){
    if(n==1){
        return m;
    }
    else{
        return m+multiplyNumbers(m,n-1);
    }
}
int main(){
    int m;
    cin>>m;
    int n;
    cin>>n;
    cout<<multiplyNumbers(m,n)<<endl;
    return 0;
}