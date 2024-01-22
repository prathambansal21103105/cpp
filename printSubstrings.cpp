#include<iostream>
using namespace std;
void printSubstrings(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i+=1;
    }
    int len_org=i;
    int l=0;
    while(l<=i-1){
        for(int k=0;k<len_org;k++){
            for(int j=l;j<=k;j++){
                cout<<input[j];
            }
            cout<<endl;
        }
        l+=1;
    }
}
int main(){
    char input[100];
    cin>>input;
    printSubstrings(input);
    return 0;
}