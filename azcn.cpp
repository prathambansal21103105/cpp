#include<iostream>
using namespace std;
void ftoc(int s,int e,int w){
    int i;
    i=s;
    while(i<=e){
        cout<<i<<" "<<((i-32)*5)/9<<endl;
        i+=w;
    }
}
int main(){
    int s,e,w;
    cin>>s>>e>>w;
    ftoc(s,e,w);
    return 0;
}