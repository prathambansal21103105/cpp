#include<iostream>
using namespace std;
void reverseEachWord(char input[]){
    int space[10000];
    int count=0;
    space[0]=0;
    for(int i=0;i<strlen(input);i++){
        if (input[i]==' '){
            count+=1;
            space[count]=i-1;
            count+=1;
            space[count]=i+1;
        }
        else{
            continue;
        }
    }
    space[count+1]=strlen(input)-1;
    for(int i=0;i<count+2;i=i+2){
        int j=i+1;
        while(space[i]<space[j]){
            int temp=input[space[i]];
            input[space[i]]=input[space[j]];
            input[space[j]]=temp;
            space[i]+=1;
            space[j]-=1;
        } 
    }
}
int main(){
    char input[100];
    cin.getline(input,100);
    reverseEachWord(input);
    cout<<input<<endl;
    return 0;
}