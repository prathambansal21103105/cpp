#include<iostream>
using namespace std;
int decimalToBinary(long n) {
    int remainder; 
    int binary=0, i = 1;
   
    while(n!=0){
        remainder=n%2;
        n=n/2;
        binary=binary+(remainder*i);
        i=i*10;
    }
    return binary;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int ans=decimalToBinary(n);
        int count=0;
        while(ans>0){
            int lastdigit=ans%10;
            ans=ans/10;
            if (lastdigit==1){
                count+=1;
            }
            else{
                count+=0;
            }
        }
        cout<<count-1<<endl;
        t-=1;
    }
    return 0;
}