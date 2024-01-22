#include<iostream>
#include<string>
using namespace std;
string getCompressedString(string str){
    char prev=str[0];
    int count=0;
    string ans="";
    int j=0;
    ans+=prev;
    j+=1;
    for(int i=0;i<str.length();i++){
        if(str[i]==prev){
            count+=1;
        }
        else{
            if (count!=1){
                ans+=to_string(count);
                j+=1;
            }
            count=1;
            prev=str[i];
            ans+=prev;
            j+=1;
        }
    }
    if (count!=1){
        ans+=to_string(count);
    }
    return ans;
}
int main(){
    string str;
    cin>>str;
    cout<<getCompressedString(str)<<endl;
    return 0;
}