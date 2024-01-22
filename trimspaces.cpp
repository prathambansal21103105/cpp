#include<iostream>
using namespace std;
void trimspaces(char input[]){
    int i=0;
    int count=0;
    while(input[i]!='\0'){
        if (input[i]!=' '){
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
    trimspaces(input);
    int i=0;
    while(input[i]!='\0'){
        cout<<input[i];
        i+=1;
    }
    cout<<endl;
    return 0;
}