#include<iostream>
#include<cstring>
using namespace std;
bool checksequence(char s[],char t[]){
    if(t[0]=='\0' and s[0]=='\0'){
        return true;
    }
    else if(t[0]=='\0' and strlen(s)!=0){
        return true;
    }
    else if(s[0]=='\0' and strlen(t)!=0){
        return false;
    }
    else{
        if(s[0]==t[0]){
            bool small=checksequence(s+1,t+1);
            return true and small;
        }
        else{
            bool small=checksequence(s+1,t);
            return true and small;
        }
    }
}
int main(){
    char s[100];
    cin>>s;
    char t[100];
    cin>>t;
    if(checksequence(s,t)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}