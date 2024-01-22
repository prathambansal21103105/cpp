#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int x;
        cin>>x;
        double final;
        final=100-((100*x)/100);
        cout<<final<<endl;
        t-=1;
    }
    return 0;
}