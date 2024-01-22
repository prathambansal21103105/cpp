#include<iostream>
using namespace std;
char highestOccuringChar(char input[]){
    int input1[100];
    for(int i=0;i<strlen(input);i++){
        int count=0;
        for(int j=0;j<strlen(input);j++){
            if (input[i]==input[j]){
                count+=1;
            }
        }
        input1[i]=count;
        if (count>=strlen(input)/2){
            return input[i];
        }
    }
    int max=input1[0];
    int index;
    for(int i=0;i<strlen(input);i++){
        if (input1[i]>max){
            max=input1[i];
            index=i;
        }
    }
    return input[index];
}
int main(){
    char input[100];
    cin>>input;
    cout<<highestOccuringChar(input)<<endl;
    return 0;
}