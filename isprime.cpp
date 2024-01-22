#include<iostream>
using namespace std;
bool isPrime(int x){
    for(int i=2;i<x;i++){
        if (x%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    for(int x=2;x<=n;x++){
        if(isPrime(x)){
            cout<<x<<endl;
        }
    }
    return 0;
}