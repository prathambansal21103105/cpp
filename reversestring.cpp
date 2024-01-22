#include<iostream>
using namespace std;
int length(char input[]){
    int count=0;
    int i=0;
    while(input[i]!='\0'){
        count+=1;
        i+=1;
    }
    return count;
}

void reverseString(char input[]){
    int len=length(input);
    int i=0,j=len-1;
    while(i<j){
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i+=1;
        j-=1;
    }
}

int main(){
    char input[100];
    cin.getline(input,100);
    reverseString(input);
    cout<<input<<endl;
    return 0;
}