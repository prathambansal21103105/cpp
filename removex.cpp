#include<iostream>
#include<cstring>
using namespace std;
void relocate(char input[]){
    int count=0;
    int i;
    for(i=0;i<strlen(input);i++){
        if(input[i]!=' '){
            input[count]=input[i];
            count+=1;
        }
    }
    input[count]='\0';
}
void removeX(char input[]){
    if(strlen(input)==1){
        if(input[0]=='x'){
            input[0]=' ';
        }
    }
    else{
        if(input[0]=='x'){
            input[0]=' ';
            relocate(input);
            removeX(input);
        }
        else{
            removeX(input+1);
        }
    }
}
int main(){
    char input[100];
    cin>>input;
    removeX(input);
    cout<<input<<endl;
    return 0;
}