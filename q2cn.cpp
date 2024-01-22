#include<iostream>
using namespace std;
int main(){
    int s,e,w;
    cin>>s>>e>>w;
    for (int i=s;i<=e;i=i+w){
        cout<<i<<" "<<int((i-32)*(5.0/9))<<endl;
    }
    return 0;
}