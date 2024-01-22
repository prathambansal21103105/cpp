#include<iostream>
#include<string>
using namespace std;
int subs(string input,string output[]){
    if(input.empty()){ // it is true if input string is empty
        output[0]="";
        return 1;
    }
    else{
        string smallstring=input.substr(1);
        int smalloutputsize=subs(smallstring,output);
        for(int i=0;i<smalloutputsize;i++){
            output[i+smalloutputsize]=input[0]+output[i];
        }
        return 2*smalloutputsize;
    }
}
int main(){
    string input;
    cin>>input;
    string*output=new string[1000];    // otherwise its length should be 2^n
    int count=subs(input,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}