#include<iostream>
#include<cstring>
#include<string>
using namespace std;
bool checkAB(char input[],int k){
    if(strlen(input)==k){
        if(input[0]=='a'){
            if(input[1]=='a'){
                return true*checkAB(input+1,k);
            }
            else if(input[1]=='b' and input[2]=='b'){
                return true*checkAB(input+1,k);
            }
            else if(input[1]=='\0'){
                return true;
            }
            else{
                return false;
            } 
        }
        else{
            return false;
        }
    }
    else if(strlen(input)==0){
        return true;
    }
    else{
        if(input[0]=='a'){
            if(input[1]=='a'){
                return true*checkAB(input+1,k);
            }
            else if(input[1]=='b' and input[2]=='b'){
                return true*checkAB(input+1,k);
            }
            else if(input[1]=='\0'){
                return true;
            }
            else{
                return false;
            }
        }
        else if(input[0]=='b' and input[1]=='b'){
            if(input[2]=='a' or input[2]=='\0'){
                return true*checkAB(input+1,k);
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }
}
bool checkab(char input[]){
    int len=strlen(input);
    return checkAB(input,len);
}
int main(){
    char s[100];
    cin>>s;
    if(checkab(s)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}