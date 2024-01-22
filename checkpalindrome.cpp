#include<iostream>
using namespace std;
bool checkPalindrome(char str[]){
    int count=0;
    int i=0;
    bool a=true;
    while(str[i]!='\0'){
        count+=1;
        i+=1;
    }
    int f=0;
    int b=count-1;
    if (count==1){
        return true;
    }
    while(f<b){
        if (str[f]==str[b]){
            f+=1;
            b-=1;
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    char c[100];
    cin>>c;
    bool ans;
    ans=checkPalindrome(c);
    if(ans){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}