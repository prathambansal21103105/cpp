#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        string str;
        cin>>str;
        int input[256]={0};
        int dist=0;
        int total=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='a' or str[i]=='e' or str[i]=='i' or str[i]=='o' or str[i]=='u'){
                input[str[i]]+=1;
            }
        }
        for(int i=0;i<256;i++){
            if(input[i]!=0){
                dist+=1;
                total+=input[i];
            }
        }
        if(total<=2){
            cout<<"SAD"<<endl;
        }
        else{
            int flag=0;
            for(int i=0;i<str.length()-2;i++){
                if((str[i]=='a' or str[i]=='e' or str[i]=='i' or str[i]=='o' or str[i]=='u') and (str[i+1]=='a' or str[i+1]=='e' or str[i+1]=='i' or str[i+1]=='o' or str[i+1]=='u') and (str[i+2]=='a' or str[i+2]=='e' or str[i+2]=='i' or str[i+2]=='o' or str[i+2]=='u')){
                    flag=1;
                    break;
                }
                else{
                    continue;
                }
            }
            if(flag==1){
                cout<<"HAPPY"<<endl;
            }
            else{
                cout<<"SAD"<<endl;
            }
        }
        t-=1;
    }
    return 0;
}