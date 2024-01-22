#include<iostream>
#include<string>
using namespace std;
long feven(int n){
    if (n>0){
    string even;
    int div=1;
    int ans;
    int c=n;
    even='1';
    while(n/2>0){
        n=n/2;
        div*=2;
        even=even+'0';
    }
    ans=stoi(even);
    return ans+feven(c-div);
    }
    else{
        return 0;
    }
}
int main(){
    int n;
    cin>>n;
    string d;
    int count=0;
    int ans;
    string even;
    even='1';
    if(n%2==0){
        d='0';
    }
    else{
        d='1';
        n=n-1;
    }
    ans=stoi(d);
    cout<<ans+feven(n)<<endl;

    return 0;
}