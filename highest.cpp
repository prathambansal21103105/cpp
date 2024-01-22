#include<iostream>
#include<cstring>
using namespace std;
char highestOccuringChar(char input[]){
    int length=strlen(input);
    int count=0;
    int countarray[100];
    int i;
    for(i=0;i<length;i++){
        char r=input[i];
        count=0;
        for(int j=0;j<length;j++){
            if (input[j]==r){
                count+=1;
            }
        }
        countarray[i]=count;
    }
    int index=i-1;
    int max=countarray[i];
    for(int j=i-1;j>=0;j--){
        if(countarray[j]>=max){
            index=j;
        }
    }
    return input[index];
}
int main(){
    char input[100];
    cin>>input;
    cout<<highestOccuringChar(input);
    cout<<endl;
    return 0;
}