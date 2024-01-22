#include<iostream>
using namespace std;
bool check(int n){
    int i=0;
    int j=1;
    int ans=0;
    while (ans<n){
        ans=i+j;
        i=j;
        j=ans;
        if (ans==n){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int ans;
    ans=check(n);
    cout<<ans<<endl;
    return 0;
}