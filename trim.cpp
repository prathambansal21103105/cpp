#include<iostream>
using namespace std;
void trimSpaces(char input[]){
    int i=0;
    int count=0;
    while(input[i]!='\0'){
        if(input[i]!=' '){
            char temp=input[i];
            input[i]=input[count];
            input[count]=temp;
            count+=1;
            i+=1;
        }
        else{
            i+=1;
        }
    }
}
int main(){
    char input[100];
    cin.getline(input,100);
    trimSpaces(input);
    cout<<input<<endl;
    return 0;
}