#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
    int a,b,c;
    cin>>a>>b>>c;
    if((c>=a and c<=b) or (a>=c and a<=b)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    t-=1;
    }
    return 0;
}