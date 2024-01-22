#include<iostream>
#include<cstring>
using namespace std;
void replacePi(char input[]){
    if(strlen(input)==1){
        cout<<input[0]<<endl;
    }
    else if(strlen(input)==2){
        if(input[0]=='p' and input[1]=='i'){
            cout<<3.14<<endl;
        }
        else{
            cout<<input[0];
            replacePi(input+1);
        }
    }
    else{
        if(input[0]=='p' and input[1]=='i'){
            cout<<3.14;
            replacePi(input+2);
        }
        else{
            cout<<input[0];
            replacePi(input+1);
        }
    }
}
int main(){
    char input[100];
    cin>>input;
    replacePi(input);
    return 0;
}