#include<iostream>
using namespace std;
bool isPrime(int num){
    for(int j=2;j<num;j++){
        if(num%j==0){
            return false;
        }
    }
    return true;
}
int main(){

    int a,b;
    cin>>a>>b;

    for(int i=a;i<=b;i++){
        if(isPrime(i)){
            cout<<i<<endl;
        }
    }






    return 0;
}