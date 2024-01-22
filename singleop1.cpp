#include<iostream>
#include<string>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    int input[100000];
    int a=2;
    for(int i=0;i<100000;i++){
        input[i]=a;
        a*=2;
    }
    while(t>0){
        int length;
        cin>>length;
        string s;
        cin>>s;
        string o="";
        int flag=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                o+='1';
                flag=1;
            }
            else if(s[i]=='1' and flag==1){
                o+='0';
            }
            else{
                continue;
            }
        }
        if(o==""){
            o+='0';
        }
        int x=stoi(s,0,2);
        int req=stoi(o,0,2);
        int d=length;
        int y=1;
        int max=x;
        int ans=1;
        while(d>0){
            int r=x/input[y-1];
            if((x xor r)>=max){
                max=x xor r;
                ans=y;
            }
            if(r==req or r==0){
                break;
            }
            d-=1;
            y+=1;
        }
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}
/*
#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int length;
        cin>>length;
        string s;
        cin>>s;
        int count1=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count1+=1;
            }
            else{
                break;
            }
        }
        cout<<count1<<endl;
        t-=1;
    }
    return 0;
}
*/