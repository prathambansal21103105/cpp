#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int x,y;
        cin>>x>>y;
        if (y<=x+200 && y>=x){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        t-=1;
    }
    return 0;
}