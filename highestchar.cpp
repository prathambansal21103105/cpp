#include<iostream>
#include<cstring>
using namespace std;
char highestOccuringChar(char input[]){
    char ans;
    int maxfreq=-1;
    int n=strlen(input);
    int count_arr[256]={0};
    
    for(int i=0;i<n;i++){
        count_arr[input[i]]+=1;
    }
    for(int i=0;i<n;i++){
        if(count_arr[input[i]]>maxfreq){
            maxfreq=count_arr[input[i]];
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