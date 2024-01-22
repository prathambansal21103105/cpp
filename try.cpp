#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char input[4]={'3','.','1','4'};
    cout<<input<<endl;
    input[5]='\0';
    cout<<strlen(input)<<endl;
    input[4]='a';
    cout<<input<<endl;
    cout<<strlen(input)<<endl;
    return 0;
}