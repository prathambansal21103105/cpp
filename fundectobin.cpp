#include<iostream>     //decimal to binary conversion
#include<math.h>
using namespace std;
int dectobin(int n){
    int bin=0;
    int count=0;
    int quotient=n;
    while(quotient>1){
        int rem=n%2;
        quotient=int(n/2);
        bin+=rem*pow(10,count);
        count+=1;
        n=int(n/2);
    }
    bin+=quotient*pow(10,count);
    return bin;
}
int main(){
    int n;
    cin>>n;
    cout<<dectobin(n)<<endl;
    return 0;
}