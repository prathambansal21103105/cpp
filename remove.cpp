#include<iostream>
using namespace std;
void swap(char a, char b){
    int temp=a;
    a=b;
    b=temp;
}
void removeAllOccurencesOfChar(char input[],char c){
    int count=0;
    char input1[10000];
    int j=0;
    for(int i=0;i<strlen(input);i++){
        if (input[i]==c){
            count+=1;
            input[i]=' ';
        }
        else{
            input1[j]=input[i];
            j+=1;
        }
    }
    if (count!=0){
        for(int i=0;i<strlen(input1)-1;i++){
            input[i]=input1[i];
        }
        for(int r=strlen(input)-count-1;r<strlen(input);r++){
            input[r]=' ';
        }
    }
}
int main(){
    char input[100];
    cin>>input;
    char c;
    cin>>c;
    removeAllOccurencesOfChar(input,c);
    cout<<input<<endl;
    return 0;
}