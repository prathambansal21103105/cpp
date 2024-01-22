#include<iostream>
#include<cstring>
using namespace std;
void change(char input[]){
    input[strlen(input)+1]='\0';
    for(int i=strlen(input);i>=3;i--){
        input[i]=input[i-1];
    }
}
void pairStar(char input[]){
    if(strlen(input)==2){
        if(input[0]==input[1]){
            input[1]='*';
            input[2]=input[0];
            input[3]='\0';
        }
    }
    else{
        if(input[0]==input[1]){
            input[1]='*';
            change(input);
            input[2]=input[0];
            pairStar(input+2);
        }
        else{
            pairStar(input+1);
        }
    }
}
int main(){
    char input[100];
    cin>>input;
    pairStar(input);
    cout<<input<<endl;
    return 0;
}
