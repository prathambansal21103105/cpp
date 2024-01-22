#include<iostream> //adding two binary numbers
#include<math.h>
using namespace std;

int bintodec(int n){
    int count=0;
    int dec=0;
    while(n>0){
        int bit=n%10;
        dec+=bit*pow(2,count);
        n=int(n/10);
        count+=1;
    }
    return dec;
}
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
int binsum(int n1,int n2){
    int decn1=bintodec(n1);
    int decn2=bintodec(n2);
    int sumdec=decn1+decn2;
    int sumbin=dectobin(sumdec);
    return sumbin;
}

int main(){
    int n1;
    int n2;
    cin>>n1>>n2;
    cout<<binsum(n1,n2)<<endl;
    return 0;
}