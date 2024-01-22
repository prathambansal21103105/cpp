#include<iostream>
using namespace std;
void change(char input[]){
    int count=0;
    int space=0;
    for(int i=0;i<strlen(input);i++){
        if(input[i]!=' '){
            input[count]=input[i];
            count+=1;
        }
        else{
            space+=1;
            input[count]=input[i];
        }
    }
    input[strlen(input)-space]='\0';
}
void removeX(char input[]){
    if(strlen(input)==1){
        if(input[0]=='x'){
            input[0]=' ';
            input[0]='\0';
        }
    }
    else{
        if(input[0]=='x'){
            input[0]=' ';
            change(input);
            removeX(input);
        }
        else{
            removeX(input+1);
        }
    }
}
int main(){
    char input[100];
    cin.getline(input,100);
    removeX(input);
    cout<<input<<endl;
    return 0;
}