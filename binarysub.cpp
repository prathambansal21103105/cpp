#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        string s;
        cin>>s;
        int countab=0;
        int countba=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='a' and s[i+1]=='b'){
                countab+=1;
            }
            if(s[i]=='b' and s[i+1]=='a'){
                countba+=1;
            }
        }
        t-=1;
    }
    return 0;
}