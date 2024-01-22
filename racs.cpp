#include<iostream>
#include<string>
using namespace std;
char get(char input){
    int ans;
    int a=int(input);
    int b=int('a');
    ans=a+b-49;
    char al=ans;
    return al;
}
int getCodes(string input,string output[]){
    if(input.length()==0){
        return 1;
    }
    else if(input.length()==1){
        output[0]=output[0]+get(input[0]);
        return 1;
    }
    else{
        int ans1=getCodes(input.substr(1),output);
        int i;
        for(i=0;i<ans1;i++){
            output[i]=get(input[0])+output[i];
        }
        int n1=input[0]-48;
        int n2=input[1]-48;
        int n3=n1*10+n2;
        int ans2=0;
        if(n3<=26){
            ans2=getCodes(input.substr(2),output+ans1);
            int n4=n3+96;
            char a=n4;
            for(int j=ans1;j<ans1+ans2;j++){
                output[j]=a+output[j];
            }
        }
        return ans1+ans2;
    }
}
int main(){
    string str;
    cin>>str;
    string output[35000];
    int ans=getCodes(str,output);
    for(int i=0;i<ans;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}