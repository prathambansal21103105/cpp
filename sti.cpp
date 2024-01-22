#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int stringToNumber(char input[]){
    if(strlen(input)==1){
        int n=int(input[0]);
        int final1=n-48;
        return final1;
    }
    else{
        int n=int(input[0]);
        int final=n-48;
        final=final*pow(10,strlen(input)-1);
        return final+stringToNumber(input+1);
    }
}
int main(){
    char input[100];
    cin>>input;
    cout<<stringToNumber(input);
    return 0;
}