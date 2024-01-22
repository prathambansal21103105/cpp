#include<iostream>
#include<string>
using namespace std;
int subsequences(string a, string output[]){
    if(a.empty()){
        output[0]="";
        return 1;
    }
    string small=a.substr(1);
    int smalloutputsize=subsequences(small,output);
    for(int i=0;i<smalloutputsize;i++){
        output[i+smalloutputsize]=a[0]+output[i];
    }
    return 2*smalloutputsize;
}
int main(){
    string a="abc";
    string output[100];
    int length=subsequences(a,output);
    for(int i=0;i<length;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}