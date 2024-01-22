#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int flag1=0;
        int flag2=0;
        int flag=0;
        int l=-1;
        int r=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                flag1=1;
                if(l==-1){
                    l=i;
                }
            }
            else{
                flag2=1;
                if(r==-1){
                    r=i;
                }
            }
            if(i+1<n){
                if(s[i]=='R' and s[i+1]=='L'){
                    flag=1;
                }
            }
        }
        if(flag1==0 or flag2==0){
            cout<<-1<<endl;
            t-=1;
            continue;
        }
        else if(r<l){
            cout<<0<<endl;
            t-=1;
            continue;
        }
        else{
            cout<<r-l<<endl;
        }

        t-=1;
    }
    return 0;
}