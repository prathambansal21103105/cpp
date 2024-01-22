#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        float a,b,c;
        cin>>a>>b>>c;
        if((a+b)/2<35 or (b+c)/2<35 or (a+c)/2<35){
            cout<<"FAIL"<<endl;
        }
        else{
            cout<<"PASS"<<endl;
        }
        t-=1;
    }
    return 0;
}