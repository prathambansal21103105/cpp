#include<iostream>
using namespace std;
void replaceCharacter(char c[],char c1,char c2){
    int i=0;
    bool a=true;
    while(a){
        if (c[i]==c1){
            c[i]=c2;
        }
        else if(c[i]=='\0'){
            a=false;
        }
        i+=1;
    }
}
int main(){
    char c[100];
    cin>>c;
    char c1,c2;
    cin>>c1>>c2;
    replaceCharacter(c,c1,c2);
    int i=0;
    while(c[i]!='\0'){
        cout<<c[i];
        i+=1;
    }
    cout<<endl;
    return 0;
}