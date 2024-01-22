#include<iostream>
using namespace std;
int countZeroes(int n){
    if(n<=9){
        if(n==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        int last_digit=n%10;
        if(last_digit==0){
            return 1+countZeroes(n/10);
        }
        else{
            return countZeroes(n/10);
        }
    }
}
int main(){
    int n;
    cin>>n;
    cout<<countZeroes(n)<<endl;
    return 0;
}