#include<iostream>
#include<string>
using namespace std;
char highestOccuringChar(char input[]){
    int count=0;
    int max=0;
    char ans;
    for(int i=strlen(input)-1;i>=0;i--){
        count=0;
        for(int j=strlen(input)-1;j>=0;j--){
            if (input[i]==input[j]){
                count+=1;
            }
        }
        if (count>=max){
            max=count;
            ans=input[i];
        }
    }
    return ans;
}
int main(){
    char input[100];
    cin>>input;
    cout<<highestOccuringChar(input)<<endl;
    return 0;
}