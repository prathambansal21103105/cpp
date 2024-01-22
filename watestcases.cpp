#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        char b[1000];
        cin>>b;
        int size=1000;
        for(int i=0;i<n;i++){
            if(b[i]=='0'){
                if(s[i]<=size){
                    size=s[i];
                }
            }
        }
        cout<<size<<endl;
        t-=1;
    }
    return 0;
}