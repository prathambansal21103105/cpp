#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int x;
        cin>>x;
        if(x<=300){
            cout<<300*10<<endl;
        }
        else{
            cout<<x*10<<endl;
        }
        t-=1;
    }
    return 0;
}