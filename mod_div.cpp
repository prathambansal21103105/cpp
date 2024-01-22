#include<iostream>
using namespace std;

int binexp(int a, int b, int M){
    if(b==0){
        return 1;
    }
    long long x=binexp(a,b/2,M)%M;
    if(b&1){
        return ((((a%M)*(x%M))%M)*(x%M))%M;
    }
    else{
        return ((x%M)*(x%M))%M;
    }
}

int main(){
    int a,b,M;
    cin>>a>>b>>M;

    // (a/b)%M
    // (a*bin)%M;
    // bin= pow(b,M-2)%M;
    //if b and M are coprime;
    int bin=binexp(b,M-2,M);
    int ans=((a%M)*(bin%M))%M;
    cout<<ans<<endl;


    return 0;
}