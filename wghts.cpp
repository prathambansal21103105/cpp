#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int w,x,y,z;
        cin>>w>>x>>y>>z;
        if(w==x+y+z or w==x+y or w==y+z or w==x+z or w==x or w==y or w==z){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        t-=1;
    }
    return 0;
}