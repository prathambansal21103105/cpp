#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int subsequence(string input, string output[]){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    else{
        string smallstring=input.substr(1);
        int smalloutputsize=subsequence(smallstring,output);
        for(int i=0;i<smalloutputsize;i++){
            output[i+smalloutputsize]=input[0]+output[i];
        }
        return 2*smalloutputsize;
    }
}
int main(){
    string input;
    cin>>input;
    int length=input.size();
    string* output=new string[1000];
    int arrlen=subsequence(input,output);
    for(int i=0;i<arrlen;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}