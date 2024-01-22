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
    int a,b;
    cin>>a>>b;

    int M;
    cin>>M;
    
    int ans=binexp(a,b,M);
    cout<<ans<<endl;

    return 0;
}