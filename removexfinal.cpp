#include<iostream>
using namespace std;
void removeX(char input[]){
    if(input[0]=='\0'){
        return;
    }
    else{
        if(input[0]!=x){
            removeX(input+1);
        }
        else{
            int i;
            for(i=1;input[i]!='\0';i++){
                input[i-1]=input[i];
            }
            input[i-1]='\0';
            removeX(input);
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