#include<iostream>
using namespace std;
void printAllPrefixes(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i+=1;
    }
    int len_org=i;
    for(int k=0;k<len_org;k++){
        for(int j=0;j<=k;j++){
            cout<<input[j];
        }
        cout<<endl;
    }
}
int main(){
    char input1[100]="abcd";
    printAllPrefixes(input1);
    return 0;
}